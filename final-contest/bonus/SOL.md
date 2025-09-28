# Bài Bonus: Trại hè

Tóm tắt đề: Cho ba số nguyên dương $a, b, d$. Tìm số nguyên dương $x$ nhỏ nhất sao cho trong trong các số $x, x + 1, \dots, x + d - 1$ có ít nhất một bội của $a$ và một bội của $b$.

## Lời giải:

Không mất tính tổng quát, giả sử $a \le b$. Đặt $t = [\sqrt{b}]$, suy ra $t^2 \ge b \ge a$.

### Trường hợp 1: $d \le t$.

Ta có thể duyệt mọi giá trị $y \le d$. Ta cần tìm một bội của $a$ và một bội của $b$ sao cho khoảng cách của chúng đúng bằng $y$, nghĩa là cần giải phương trình Diophantine $am - bn = y$ và/hoặc $bm - an = y$. Sau khi có được họ nghiệm của mỗi phương trình, ta có thể tìm ra giá trị $n$ nhỏ nhất lớn hơn $0$ sao cho tồn tại một giá trị $m$ mà $(m, n)$ là nghiệm của phương trình. Từ đây ta tìm được giá trị $x$ lớn hơn $0$ trong hai giá trị bội có hai số, từ đó tìm được ngày $x$ tương ứng với khoảng cách $y$ và giải quyết được bài toán.

---

### Trường hợp 2: $d > t$.

Gọi $x_1 = b \bmod a, x_2 = 2b \bmod a, \dots, x_t = tb \bmod a$. Ta chia các số dư từ $0$ đến $a - 1$ thành $t$ nhóm, mỗi nhóm gồm không quá $t$ giá trị. Nếu tồn tại hai giá trị $x_m$ và $x_n$ cùng một nhóm, nghĩa là $|mb \bmod a - nb \bmod a| \le \lfloor \frac{a-1}{t} \rfloor \le t \le d$. Ngược lại, nếu tất cả các giá trị đều thuộc các nhóm khác nhau, nghĩa là tồn tại một giá trị $x_m$ nằm trong đoạn $[0, t - 1]$ hay $mb \bmod a \le t$. Cả hai trường hợp đều dẫn đến việc tồn tại một giá trị $k \le t$ sao cho $|kb \bmod a| \le t$. Đến đây, ta chỉ cần duyệt tất cả các bội của $b$ không vượt quá $bt$, sau đó tìm bội của $a$ gần nhất và kiểm tra để giải quyết bài toán.

---

Trường hợp 1 và 2, có thể thấy rằng bài toán có thể được giải quyết trong độ phức tạp $O(T (\sqrt{b} \log b))$ hoặc $O(T \sqrt{b})$ tùy cách cài đặt.