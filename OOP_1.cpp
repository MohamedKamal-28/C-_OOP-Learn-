#include <iostream> 
using namespace std ;
class Car{

    // Encapsulation 
    private : 
    // Properites (Attributes)
    string brand ; 
    string model ; 
    int year ; 
    bool isExpired() {
        int current_year = 2026 ; 
        return (current_year - year > 15  ) ;    
    } ; 

    public: 
    Car(){
        setBrand("Unkown")  ; 
        setModel("Unkown") ; 
        setYear(0) ; 
    }
    Car(string b , string m , int y ) {
        setBrand(b) ; 
        setModel(m) ; 
        setYear(y)  ;
    }
    // Methods 
    virtual void displayinfo() {
        cout<< "Brand: "<< brand << endl ; 
        cout<< "Model: "<< model << endl; 
        cout<< "Year: "<< year << endl; 
        cout<< "Is expired: "<< (isExpired() ? "Yes" : "No") << endl; // ternary Operator 
    }
    // Polymorphism Overloading 
    virtual void displayinfo(string UserName){
        cout<< "User Name : " << UserName << endl; 
        displayinfo() ; 
    }
    void setBrand(string brand_name){ 
        brand = brand_name ; 
    } 
    string getBrand(){
        return brand ; 
    }

    void setModel(string model_name){ 
        model = model_name ; 
    } 
    string getModel(){
        return model ; 
    }

    void setYear(int no_year){ 
        year = no_year ; 
    } 
    int getYear(){
        return year ; 
    }
} ; 
///////////////////////////////////////////////////////////////////////////////////////////
class ElectricCar : public Car {
    private : 
    int batteryCapacity ; 
    public  :
    ElectricCar(string b , string m , int y , int c){
        Car:: setBrand(b) ; 
        Car:: setModel(m) ; 
        Car:: setYear(y) ; 
        setBaterryCapacity(c) ; 
    }
    // Polymorphism Override 
    void displayinfo() override { 
        Car :: displayinfo() ; 
        cout<< "Battery Capacity: "<< batteryCapacity << endl; 
    } 
    void displayinfo(string UserName) override {
        cout<< "User Name "<< UserName << endl; 
        displayinfo()  ; 
    }



    void setBaterryCapacity(int c){
        batteryCapacity = c ; 
    }
    int getBatteryCapacity(){
        return  batteryCapacity  ; 
    }
}  ; 
int main(){
    // Objects 
    Car car1  ; 
    car1.displayinfo() ; 
    cout<<"==================" << endl; 

    ElectricCar ecar("Tesla" ,"X", 2025, 95) ;
    ecar.displayinfo("Mohamed Kamal") ; 
    return 0 ; 
}