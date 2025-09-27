# SOLUTION PROBLEM 4: XÓA ĐOẠN

Đề bài: **[DRANGE.md](../DRANGE.md)**
Code: **[SOL.cpp](SOL.cpp)**

---

**Nhận xét:** Một dãy $b$ có $n$ phần tử là đẹp khi và chỉ khi tồn tại một bộ $k \ge 0$ vị trí $1 < x_1 < x_2 < \dots < x_k < n$ sao cho:

$$
\begin{cases}
x_k + a_{x_k} - 1 \le n \\
x_{k-1} + a_{x_{k-1}} + a_{x_k} - 1 \le n \\
x_{k-2} + a_{x_{k-2}} + a_{x_{k-1}} + a_{x_k} - 1 \le n \\
\dots \\
x_1 + a_{x_1} + a_{x_2} + \dots + a_{x_{k-1}} + a_{x_k} - 1 \le n \\
1 + a_1 + a_{x_1}+ a_{x_2} + \dots + a_{x_{k-1}} + a_{x_k} - 1 = n
\end{cases}
$$

với $a_i = b_i + 1$

**Chứng minh:**

*Phần thuận* $–$ dãy $b$ là đẹp nếu điều kiện thỏa mãn.

Ta thấy rằng có thể biến dãy thành dãy rỗng bằng cách xóa các khối bắt đầu từ các phần tử $b_{x_k} \to b_{x_k-1} \to \dots \to b_2 \to b_1 \to 1$. Cụ thể:

* Ban đầu dãy có $n - x_k$ phần tử bên phải phần tử $b_{x_k}$.
* Xóa $a_{x_k}$ phần tử bắt đầu từ vị trí $x_k$. Khi này dãy còn $n - a_{x_k} - x_{k-1}$ phần tử bên phải phần tử $b_{x_{k-1}}$.
* Xóa $a_{x_{k-1}}$ phần tử bắt đầu từ vị trí $x_{k}$. Khi này dãy còn $n - a_{x_k} - a_{x_{k-1}} - x_{k-2}$ phần tử bên phải phần tử $b_{x_{k-2}}$.
* $\dots$
* Xóa $a_{x_2}$ phần tử bắt đầu từ vị trí $x_2$. Khi này dãy còn $n - a_{x_k} - a_{x_{k-1}} - \dots - a_{x_2} - x_1$ phần tử bên phải phần tử $b_{x_1}$.
* Xóa $a_{x_1}$ phần tử bắt đầu từ vị trí $x_1$. Khi này dãy còn $n - a_{x_k} - a_{x_{k-1}} - \dots - a_{x_1} - 1$ phần tử.
* Xóa $a_1$ phần tử bắt đầu từ vị trí $1$. Khi này dãy còn $n - a_{x_k} - a_{x_{k-1}} - \dots - a_{x_1} - a_1$ phần tử.

Như vậy, ta cần các điều kiện sau thỏa mãn:

$$
\begin{cases}
n - x_k \ge b_{x_k} \\
n - a_{x_k} - x_{k-1} \ge b_{x_{k-1}} \\
\dots \\
n - a_{x_k} - a_{x_{k-1}} - \dots - a_{x_2} - x_1 \ge b_{x_1} \\
n - a_{x_k} - a_{x_{k-1}} - \dots - a_{x_1} - 1 \ge b_{1} \\
n - a_{x_k} - a_{x_{k-1}} - \dots - a_{x_1} - a_1 = 0
\end{cases}
$$

Biến đổi từng điều kiện trên có thể dễ dàng thu được các điều kiện trong giả thuyết.

*Phần đảo* $–$ điều kiện thỏa mãn nếu dãy $b$ là đẹp.

Giả sử dãy $b$ có thể được biến thành dãy rỗng nếu xóa các khối bắt đầu từ các vị trí $x_1, x_2, \dots, x_k$.

Gọi $y_1, y_2, \dots, y_k$ là dãy $x$ được sắp xếp tăng dần. Ta nhận thấy rằng có thể xóa các khối theo thứ tự $y_k \to y_{k-1} \to y_{k-2} \to \dots \to y_2 \to y_1$. Phần chứng minh, với ý tưởng tương tự như phần thuận, xin nhường cho bạn đọc.

Trở lại bài toán:

Gọi $f(l, i)$ là giá trị $r$ nhỏ nhất thỏa mãn: tồn tại một bộ $k > 0$ vị trí $l \le x_1 < x_2 < \dots < x_k < r - 1$ sao cho $b_{x_1} + b_{x_2} + \dots + b_{x_k-1} + b_{x_k} = i$ và:

$$
\begin{cases}
x_k + b_{x_k} \le r \\
x_{k-1} + b_{x_{k-1}} + b_{x_k} \le r \\
x_{k-2} + b_{x_{k-2}} + b_{x_{k-1}} + b_{x_k} \le r \\
\dots \\
x_1 + b_{x_1} + b_{x_2} + \dots + b_{x_{k-1}} + b_{x_k} \le r
\end{cases}
$$

với $b_i = a_i + 1$.

Để thấy, đoạn $(l, l + i - 1)$ là dãy đẹp khi và chỉ khi $f(l, i) = l + i$, vì chỉ có trong trường hợp đó mới có $x_1 = l$ và dấu bằng ở bất đẳng thức cuối cùng xảy ra.

Duyệt các giá trị $l$ từ $n$ về $1$. $f(l, i)$ được tính như sau:

* Nếu $i = 0$, $f(l, i) = 0$ (không có vị trí nào)
* Nếu $i < b_i$, $f(l, i) = f(l + 1, i)$ (giữ nguyên)
* Nếu $i \ge b_i$, $f(l, i) = \min(f(l + 1, i), \max(f(l + 1, i - b_i), l + i))$ (giữ nguyên hoặc bổ sung thêm $i$ vào tập các vị trí $x$)

Chúng ta chỉ cần đếm những cặp số $(l, i)$ thỏa $f(l, i) = l + i$. Đến đây, bài toán được giải quyết trong độ phức tạp $O(n^2)$.