#include "iostream"
using namespace std;


class Complex{

    private:   // private member - can be accessed by friend function
        int real;
        int imaginary;

    public:
        Complex(int real, int imaginary){  //Constructor
            this->real= real;
            this->imaginary=imaginary;
        };

        Complex(){            //Default Constructor
            real = 0;
            imaginary = 0;
        }


        Complex operator + (Complex const &a){      // Overloading + operator
            Complex sum;
            sum.real = real + a.real;
            sum.imaginary = imaginary + a.imaginary;
       
            return sum;
        };

        // Complex operator * (Complex const &a){   // Overloading * operator wihtout using friend funciton
        //     Complex product;
        //     product.real = real * a.real;
        //     product.imaginary = imaginary * a.imaginary;
        //     cout<<"The product is : ";
   
        //     return product;
        // };

        friend Complex operator*(Complex& obj1, Complex& obj2); 

        friend ostream& operator<<(ostream& out, const Complex& c);
        friend istream& operator>>(istream& in, Complex& c);

};

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real << " + i" << c.imaginary;
    return out;
}

istream& operator>>(istream& in, Complex& c) {
    cout << "Enter Real Part: ";
    in >> c.real;
    cout << "Enter Imaginary Part: ";
    in >> c.imaginary;
    return in;
}


Complex operator*(Complex& obj1, Complex& obj2){                        // Overloading * operator  using friend function
    Complex product;
    product.real = obj1.real * obj2.real - obj1.imaginary * obj2.imaginary;
    product.imaginary = obj1.real * obj2.imaginary + obj1.imaginary * obj2.real;

    return product;
};

int main(){
    Complex Default;
    cout<< "This object is constructed using Default Constructor : "<<Default<<endl;

    Complex a;
    cin>>a;
    cout << "The complex object is: " << a << endl;
    Complex b;
    cin>>b;
    cout << "The complex object is: " << b << endl;
    Complex c = a + b;
    cout << "The sum is: " << c << endl;
    Complex d = a * b;
    cout << "The product is: " << d << endl;
    return 0;
}