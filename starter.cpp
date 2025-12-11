#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Shape {
protected:
    std::string color;
    
public:
    // TASK 1: Implement the constructor to initialize the 'color' attribute.
    Shape(std::string c) : color(c) {}
    
    // TASK 2: Define the pure virtual function for drawing, named 'draw'.
    virtual void draw() = 0;
    
    // TASK 3: Define a virtual destructor.
    // This allows the 'delete' operator to call the derived destructor first, avoiding memory leaks.
    virtual ~Shape() {
        std::cout << "Base (Shape) destructor for " << color << "." << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    // TASK 4: Implement the Circle constructor.
    Circle(std::string c, double r) : Shape(c), radius(r) {}
    
    // TASK 5: Implement the 'draw' function.
    void draw() override {
        std::cout << color << " circle with radius " << radius << "." << std::endl;
    }
    
    // TASK 6: Include a derived destructor.
    ~Circle() {
        std::cout << "Circle destructor." << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    // TASK 7: Implement the Rectangle constructor.
    Rectangle(std::string c, double w, double h) : Shape(c), width(w), height(h) {}
    
    // TASK 8: Implement the 'draw' function.
    void draw() override {
        std::cout << color << " rectangle (" << width << " x " << height << ")." << std::endl;
    }
    
    // TASK 9: Include a derived destructor.
    ~Rectangle() {
        std::cout << "Rectangle destructor." << std::endl;
    }
};

int main() {
    // --- SMART POINTERS SECTION ---
    std::vector<std::unique_ptr<Shape>> canvas;

    // TASK 10: Create a "Red" Circle (radius 5.0)
    canvas.push_back(std::make_unique<Circle>("Red", 5.0));
    
    // TASK 11: Create a "Blue" Rectangle (10.0 x 8.0)
    canvas.push_back(std::make_unique<Rectangle>("Blue", 10.0, 8.0));

    // TASK 12: Call the draw method polymorphically.
    for (const auto& s : canvas) {
        s->draw();
    }

    std::cout << "\n--- Clearing Canvas (Smart Pointers) ---" << std::endl;
    canvas.clear(); 
    // unique_ptrs automatically delete their objects here.


    // --- MANUAL MEMORY MANAGEMENT SECTION ---
    
    // TASK 13: Create an object using a raw pointer and delete it properly.
    std::cout << "\n--- TASK 13: Manual Memory Management ---" << std::endl;
    
    // 1. Allocate memory on the heap. 'rawShape' is type Shape*, but points to a Circle.
    Shape* rawShape = new Circle("Green", 2.0);
    
    // 2. Use the object.
    rawShape->draw();
    
    // 3. Delete the object.
    // Because ~Shape() is VIRTUAL, this line:
    //    a. Looks up the actual type (Circle).
    //    b. Calls ~Circle() (cleaning up Circle-specific resources).
    //    c. Calls ~Shape() (cleaning up Base resources).
    delete rawShape; 

    return 0;
}
