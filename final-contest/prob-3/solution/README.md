# SOLUTION PROBLEM 3: TỔNG LỚN NHẤT

Đề bài: **[MAXSUM.md](../MAXSUM.md)**
Code: **[SOL.cpp](SOL.cpp)**

---

Đầu tiên, chúng ta cần giải quyết bài toán với $k = 1$ trước.

Gọi $f(i, j)$ là tổng lớn nhất có thể tạo được nếu bắt buộc chọn phần tử $a_i$ và:
- Số $b_1$ chưa được sử dụng (sau khi xét phần tử $i$) nếu $j = 0$.
- Số $b_1$ sẽ được sử dụng cho phần tử $a_{i + 1}$ nếu $j = 1$.
- Số $b_1$ đã được sử dụng trước đó (và sẽ không được sử dụng nữa) nếu $j = 2$.

$f(i, j)$ sẽ là $\max$ của các trường hợp sau:
- $\max (0, f(i - 1, j)) + a_i \times mul_j$, với $mul_j = b_1$ nếu $j = 1$, ngược lại $mul_j = 1$: chọn phần tử $a_i$ với đúng "mask" là $j$.
- $\max (f(i, k))$ với $0 \le k < j$: phần tử $a_i$ đã được chọn với một "mask" khác - việc chuyển "mask" là để chuẩn bị cho phần tử $a_{i + 1}$.

Lưu ý rằng, chúng ta chỉ quan tâm việc thực hiện phép nhân nếu đoạn mà nó thực hiện nằm trong phần tổng lớn nhất (mà chúng ta sẽ chọn cuối cùng). Những phép nhân phía ngoài sẽ không ảnh hưởng đến tổng cuối cùng nên chúng ta không cần thiết phải quan tâm.

Từ $k = 1$, không khó để chuyển bài toán thành $k \le 6$, chỉ đơn giản là $j$ là một số trong đoạn $[0, 3^k - 1]$ và được viết trong hệ tam phân.

Độ phức tạp: $O(n \times 3^k \times k)$.