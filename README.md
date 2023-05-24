# ![](https://drive.google.com/uc?id=10INx5_pkhMcYRdx_OO4rXNXxcsvPtBYq) Visitor 訪問者模式
> ##### 理論請自行找，網路上有很多相關的文章，這邊只關注於範例實作的部分.

---

<!--ts-->
## 目錄
* [目的](#目的)
* [使用時機](#使用時機)
* [URL結構圖](#url結構圖)
* [實作成員](#實作成員)
* [實作範例](#實作範例)
* [參考資料](#參考資料)
<!--te-->

---

## 目的
Visitor模式用於在不更改被訪問的元素的類別的前提下，定義對這些元素的操作。

---

## 使用時機
當需要對一組類別進行類似的操作，但是不能夠在每個元素的類別中實現該操作時，可以使用Visitor模式。<br>
此外，當元素的結構固定，但是需要在其上定義新的操作時，也可以使用此模式。

---

## URL結構圖
![](https://drive.google.com/uc?id=1wrnOM2MT7578ItyMMX5Oicbz9KY07axT)
> 圖片來源：[Refactoring.Guru - Visitor](https://refactoring.guru/design-patterns/visitor)

---

## 實作成員
* Visitor
  * 定義對每個元素的操作。
* ConcreteVisitor
  * 實現Visitor介面以定義具體的操作。
* Element
  * 定義接受訪問者的介面。
* ConcreteElement
  * 實現Element介面，並提供一個方法讓訪問者對其進行操作。
* ObjectStructure
  * 維護元素的集合，並提供一個方法讓訪問者訪問元素。

---

## 實作範例:
- [Example](https://github.com/RC-Dev-Tech/design-pattern-visitor/blob/main/C%2B%2B/main.cpp) - Visitor Pattern (C++) 

---

## 參考資料
* [Wiki - Visitor Pattern](https://en.wikipedia.org/wiki/Visitor_pattern) <br>
* [Refactoring.Guru - Visitor](https://refactoring.guru/design-patterns/visitor) <br>

---

<!--ts-->
#### [目錄 ↩](#目錄)
<!--te-->
---
