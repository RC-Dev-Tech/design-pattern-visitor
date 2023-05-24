/*
 * Design Pattern - Visitor 訪問者模式
 * 
 * 在這個範例中，Visitor模式的主要組件是Visitor、ConcreteVisitor、Element、ConcreteElement和ObjectStructure。
 * Visitor是一個介面，定義了對每個元素的操作。ConcreteVisitor是Visitor的具體實現，根據需要實現對每個元素的具體操作。
 * Element是一個介面，定義了接受訪問者的操作。ConcreteElement是Element的具體實現，並提供了一個方法讓訪問者對其進行操作。
 * ObjectStructure維護了元素的集合，並提供了一個方法讓訪問者訪問元素。
 * 
 * 在客戶端代碼中，我們創建了一個ObjectStructure對象，並將ConcreteElementA和ConcreteElementB添加到該對象中。
 * 然後創建了一個ConcreteVisitor對象，並使用ObjectStructure的AcceptVisitor方法來讓訪問者訪問元素。
 * 當訪問者訪問每個元素時，將根據元素的類型調用相應的操作。
 */

#include <iostream>
#include <vector>

// Forward declarations
class ConcreteElementA;
class ConcreteElementB;

// Visitor interface
class Visitor {
public:
    virtual ~Visitor() {}
    virtual void VisitConcreteElementA(ConcreteElementA* element) = 0;
    virtual void VisitConcreteElementB(ConcreteElementB* element) = 0;
};

// Concrete visitor
class ConcreteVisitor : public Visitor {
public:
    void VisitConcreteElementA(ConcreteElementA* element) override;
    void VisitConcreteElementB(ConcreteElementB* element) override;
};

// Element interface
class Element {
public:
    virtual ~Element() {}
    virtual void Accept(Visitor* visitor) = 0;
};

// Concrete element A
class ConcreteElementA : public Element {
public:
    void Accept(Visitor* visitor) override {
        visitor->VisitConcreteElementA(this);
    }

    void OperationA() {
        std::cout << "ConcreteElementA operation" << std::endl;
    }
};

// Concrete element B
class ConcreteElementB : public Element {
public:
    void Accept(Visitor* visitor) override {
        visitor->VisitConcreteElementB(this);
    }

    void OperationB() {
        std::cout << "ConcreteElementB operation" << std::endl;
    }
};

// Object structure
class ObjectStructure {
private:
    std::vector<Element*> elements;

public:
    ~ObjectStructure() {
        for (auto element : elements) {
            delete element;
        }
        elements.clear();
    }

    void AddElement(Element* element) {
        elements.push_back(element);
    }

    void AcceptVisitor(Visitor* visitor) {
        for (auto element : elements) {
            element->Accept(visitor);
        }
    }
};

// Implementation of visitor's operations for concrete elements
void ConcreteVisitor::VisitConcreteElementA(ConcreteElementA* element) {
    element->OperationA();
}

void ConcreteVisitor::VisitConcreteElementB(ConcreteElementB* element) {
    element->OperationB();
}

// Client code
int main() {
    ObjectStructure objectStructure;
    objectStructure.AddElement(new ConcreteElementA());
    objectStructure.AddElement(new ConcreteElementB());

    ConcreteVisitor visitor;
    objectStructure.AcceptVisitor(&visitor);

    return 0;
}
