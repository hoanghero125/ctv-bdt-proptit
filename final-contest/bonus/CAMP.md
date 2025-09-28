Câu lạc bộ SQRT dự định tổ chức các đợt trại hè Tin học dành cho học sinh. Câu lạc bộ muốn mời hai thí sinh IOI, LKT và ĐHH, đến giao lưu với các trại sinh. Tuy nhiên, lịch trình của hai vị khách mời này rất bận rộn nên họ chỉ có thể đến giao lưu với các trại sinh trong một số ngày nhất định, cụ thể:
- LKT chỉ có thể đến được vào những ngày là bội của $a$, nghĩa là các ngày $a, 2a, 3a, \dots$.
- ĐHH chỉ có thể đến được vào những ngày là bội của $b$, nghĩa là các ngày $b, 2b, 3b, \dots$.

biết rằng hôm nay là ngày $1$.

Câu lạc bộ SQRT muốn tổ chức trại hè trong $d$ ngày, bắt đầu từ ngày thứ $k$. Hay nói cách khác, trại hè sẽ diễn ra trong các ngày $k, k + 1, k + 2, \dots, k + d - 1$. Câu lạc bộ muốn trong $d$ ngày này, phải có ít nhất một ngày LKT có thể đến giao lưu, và ít nhất một ngày ĐHH có thể đến giao lưu. Lưu ý rằng hai ngày này có thể trùng nhau. Các bạn hãy giúp câu lạc bộ SQRT tìm ra thời điểm sớm nhất mà câu lạc bộ SQRT có thể bắt đầu trại hè, hay nói cách khác, tìm ra giá trị $k$ nhỏ nhất.

---

## Dữ liệu:
- Dòng đầu tiên gồm một số nguyên dương $T$ là số bộ dữ liệu $(1 \le T \le 100)$.
- $T$ dòng tiếp theo, mỗi dòng gồm ba số nguyên dương $a, b, d$ $(1 \le a, b, d \le 3 \times 10^9)$.

---

## Kết quả:
- Với mỗi bộ dữ liệu, in ra kết quả trên một dòng.

---

## Chấm điểm

| Điểm | Ràng buộc bổ sung |
|:---:|:---|
| $6$ | $d = 1$ |
| $13$ | $a, b \le 200$ |
| $15$ | $a, b \le 2 \times 10^4$ |
| $27$ | $d \le 2$ |
| $39$ | Không có ràng buộc gì thêm |

---

## Ví dụ

### Dữ liệu
```

2
5 7 3
5 7 2

```

### Kết quả
```

5
14

```

### Giải thích

- Ở bộ dữ liệu đầu tiên, trại hè diễn ra vào các ngày $5, 6, 7$. LKT có thể đến giao lưu vào ngày $5$, trong khi ĐHH có thể đến giao lưu vào ngày $7$.
- Ở bộ dữ liệu thứ hai, trại hè diễn ra vào các ngày $14, 15$. LKT có thể đến giao lưu vào ngày $15$, trong khi ĐHH có thể đến giao lưu vào ngày $14$.