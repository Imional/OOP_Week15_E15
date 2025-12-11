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
    // Setting it to '= 0' makes this class Abstract (it cannot be instantiated directly).
    virtual void draw() = 0;
    
    // TASK 3: Define a virtual destructor.
    // Inside, print: "Base (Shape) destructor for 'color'.
    // A virtual destructor ensures the derived class destructor is called when deleting via a base pointer.
    virtual ~Shape() {
        std::cout << "Base (Shape) destructor for " << color << "." << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    // TASK 4: Implement the Circle constructor. It must call the Base (Shape) constructor.
    Circle(std::string c, double r) : Shape(c), radius(r) {}
    
    // TASK 5: Implement the 'draw' function, using the 'override' keyword.
    // Inside, print: "'color' circle with radius 'radius'."
    void draw() override {
        std::cout << color << " circle with radius " << radius << "." << std::endl;
    }
    
    // TASK 6: Include a derived destructor.
    // Inside, print: "Circle destructor."
    ~Circle() {
        std::cout << "Circle destructor." << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    // TASK 7: Implement the Rectangle constructor, calling the Base (Shape) constructor.
    Rectangle(std::string c, double w, double h) : Shape(c), width(w), height(h) {}
    
    // TASK 8: Implement the 'draw' function, using the 'override' keyword.
    // Inside, print: "'color' rectangle ('width' x 'height')."
    void draw() override {
        std::cout << color << " rectangle (" << width << " x " << height << ")." << std::endl;
    }
    
    // TASK 9: Include a derived destructor.
    // Inside, print: "Rectangle destructor."
    ~Rectangle() {
        std::cout << "Rectangle destructor." << std::endl;
    }
};

int main() {
    // Vector holds unique pointers to Shape. This allows polymorphism (storing different derived types).
    std::vector<std::unique_ptr<Shape>> canvas;

    // TASK 10: Create a "Red" Circle (with radius 5.0) and add its pointer to the canvas.
    // Use std::make_unique and push_back functions.
    canvas.push_back(std::make_unique<Circle>("Red", 5.0));
    
    // TASK 11: Create a "Blue" Rectangle (10.0 x 8.0) and add its pointer to the canvas.
    canvas.push_back(std::make_unique<Rectangle>("Blue", 10.0, 8.0));

    for (const auto& s : canvas) {
        // TASK 12: Call the draw method polymorphically.
        // 's' is a unique_ptr, so we use arrow operator '->' to access member functions.
        s->draw();
    }

    // When clear() is called, the unique_ptrs go out of scope, automatically calling the destructors.
    std::cout << "\n--- Clearing Canvas ---" << std::endl;
    canvas.clear();

    return 0;
}