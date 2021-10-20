class HierarchicalInheritance { 
	void DisplayA() { 
		System.out.println("This is a content of parent class"); 
	} 
} 

//B.java 
class A extends HierarchicalInheritance { 
	void DisplayB() { 
		System.out.println("This is a content of child class 1"); 
	} 
} 

//c.java 
class B extends HierarchicalInheritance { 
	void DisplayC() { 
		System.out.println("This is a content of child class 2"); 
	} 
} 

//MainClass.java 
public class HierarchicalInheritanceMain { 
	public static void main(String args[]) { 
		System.out.println("Calling for child class C"); 
		B b = new B(); 
		b.DisplayA(); 
		b.DisplayC(); 
		System.out.println("Calling for child class B"); 
		A a = new A(); 
		a.DisplayA();
		a.DisplayB();
	} 
} 

/*
Theorey:
Inheritance is when an object or class is based on another object or class, using the same implementation specifying implementation to maintain the same behavior. It is a mechanism for code reuse and to allow independent extensions of the original software via public classes and interfaces. The relationships of objects or classes through inheritance give rise to a hierarchy. In hierarchical inheritance a single class serves as a superclass (base class) for more than one sub class.
*/

/*
Output:
Calling for child class C
This is a content of parent class
This is a content of child class 2
Calling for child class B
This is a content of parent class
This is a content of child class 1
*/
