#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Định nghĩa __int128, được hỗ trợ như một extension trong GCC/Clang C
typedef __int128 int128;

// Macro max đơn giản
#define max(a, b) ((a) > (b) ? (a) : (b))

// Hàm tính Ước chung lớn nhất (GCD) cho long long
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        long long temp = a;
        a = b;
        b = temp;
    }
    return a;
}

// Hàm Euclidean mở rộng
long long extendedGcd(long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd_val = extendedGcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd_val;
}

// Hàm chuyển int128 sang long long (an toàn nếu giá trị nhỏ)
long long int128_to_ll(int128 val) {
    // Check if the value is within the range of long long (2^63 - 1)
    if (val > 9223372036854775807LL) return -1;
    return (long long)val;
}

void solve() {
    long long a, b, d;
    if (scanf("%lld %lld %lld", &a, &b, &d) != 3) return;

    // Tính giới hạn sqrt, dùng sqrt(double)
    long long limit_a_sqrt = (long long)ceil(sqrt((double)a));
    long long limit_b_sqrt = (long long)ceil(sqrt((double)b));
    long long limit_d = max(limit_a_sqrt, limit_b_sqrt);

    int128 min_k = -1;

    if (d - 1 >= limit_d) {
        // TRƯỜNG HỢP 1: d lớn -> Dùng thuật toán O(sqrt(a) + sqrt(b))
        long long g = gcd(a, b);
        int128 lcm = (int128)a / g * b;
        min_k = lcm - d + 1;

        // Tìm kiếm giới hạn theo a
        long long limit_m = 2 * limit_a_sqrt;
        for (long long m = 1; m <= limit_m; ++m) {
            int128 x = (int128)m * a;
            int128 n_floor = x / b;
            
            // Ứng viên 1: Bội của b ở dưới hoặc bằng x
            if (n_floor > 0) {
                int128 y1 = n_floor * b;
                if (x - y1 <= d - 1) {
                    int128 current_k = max(x, y1) - d + 1;
                    if (min_k == -1 || current_k < min_k) min_k = current_k;
                }
            }
            
            // Ứng viên 2: Bội của b ở trên x
            int128 y2 = (n_floor + 1) * b;
            if (y2 - x <= d - 1) {
                int128 current_k = max(x, y2) - d + 1;
                if (min_k == -1 || current_k < min_k) min_k = current_k;
            }
        }
        
        // Tìm kiếm giới hạn theo b
        long long limit_n = 2 * limit_b_sqrt;
        for (long long n = 1; n <= limit_n; ++n) {
            int128 y = (int128)n * b;
            int128 m_floor = y / a;

            // Ứng viên 1: Bội của a ở dưới hoặc bằng y
            if (m_floor > 0) {
                int128 x1 = m_floor * a;
                if (y - x1 <= d - 1) {
                    int128 k_cand_ll = max(x1, y) - d + 1;
                    int128 current_k = max(k_cand_ll, (int128)1); 
                    if (min_k == -1 || current_k < min_k) min_k = current_k;
                }
            }

            // Ứng viên 2: Bội của a ở trên y
            int128 x2 = (m_floor + 1) * a;
            if (x2 - y <= d - 1) {
                int128 k_cand_ll = max(x2, y) - d + 1;
                int128 current_k = max(k_cand_ll, (int128)1);
                if (min_k == -1 || current_k < min_k) min_k = current_k;
            }
        }

    } else {
        // TRƯỜNG HỢP 2: d nhỏ -> Duyệt mọi khoảng cách r = c*g
        long long m_base, n_base_neg;
        long long g = extendedGcd(a, b, &m_base, &n_base_neg);
        // Removed: long long n_base = -n_base_neg;

        int128 lcm = (int128)a / g * b;
        min_k = lcm - d + 1;

        long long limit_c = (d - 1) / g;

        for (long long c = 1; c <= limit_c; ++c) {
            // Removed: long long a_prime = a / g;
            long long b_prime = b / g;

            // TH 2.1: ma - nb = c*g
            int128 m_part1 = (int128)c * m_base;
            int128 m_sol1 = m_part1 % b_prime;
            if (m_sol1 <= 0) m_sol1 += b_prime;
            
            int128 n_sol1 = (m_sol1 * a - (int128)c * g) / b;
            
            if (n_sol1 > 0) {
                int128 x = m_sol1 * a;
                int128 y = n_sol1 * b;
                int128 k_cand = max(x, y) - d + 1;
                if (min_k == -1 || k_cand < min_k) min_k = k_cand;
            }

            // TH 2.2: nb - ma = c*g (hay ma - nb = -c*g)
            int128 m_part2 = (int128)-c * m_base;
            int128 m_sol2 = m_part2 % b_prime;
            if (m_sol2 <= 0) m_sol2 += b_prime;
            
            int128 n_sol2 = (m_sol2 * a + (int128)c * g) / b;
            
            if (n_sol2 > 0) {
                int128 x = m_sol2 * a;
                int128 y = n_sol2 * b;
                int128 k_cand = max(x, y) - d + 1;
                if (min_k == -1 || k_cand < min_k) min_k = k_cand;
            }
        }
    }
    
    long long final_k = int128_to_ll(min_k);
    
    printf("%lld\n", max(1LL, final_k));
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 1;
    while (t--) {
        solve();
    }
    return 0;
}