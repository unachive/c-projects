#include<iostream>
#include<memory>


using namespace std;

class iengine {
string name;
public:
iengine(string e="defoult"): name(e) {}
virtual ~iengine() = default;
virtual string start() {return name;}

};

class diesel_engine : public iengine {
    public:

diesel_engine(string n="disel"): iengine(n) {}
};

class petrol_engine : public iengine {
public:
    petrol_engine (string n="petrol") : iengine(n) {}
};
class hybrid_engine : public iengine {
    public:
    hybrid_engine(string n="hybrind"):iengine(n) {}


    
};

//engines end here


enum class eg_type {
   petrol,disel,hybrid
};
class ivehicle {
string vtype {"unk"} ;
unique_ptr<iengine> eng;
protected:
void set_engine(eg_type type) {
switch(type) {
case eg_type::petrol: eng = make_unique<petrol_engine>(); break;
case eg_type::disel: eng = make_unique<diesel_engine>();break;
case eg_type::hybrid: eng = make_unique<hybrid_engine>();break;
}

}
void drive() {cout <<"the "<<vtype <<" is currently driving running on "<< eng->start()<< endl;}
//constucktor is here
void set_vtype(string vt = "unk") {vtype = vt;}
public:
ivehicle(eg_type t = eg_type::petrol) {set_engine(t);}
void Ini() {cout<<"the "<<eng->start()<<" has started the "<<vtype<<" will be driviing now \n";
drive();
}


};

class truck : public ivehicle {
public:
    truck(eg_type t) : ivehicle(t) {set_vtype("truck");}
};

class car : public ivehicle {
public:
car(eg_type t) : ivehicle(t) {set_vtype("car");}

};
class heavy_truck : public ivehicle {
public:
heavy_truck(eg_type t) : ivehicle(t) {set_vtype("heavy truck");}

};

int main()
{
unique_ptr<ivehicle> v1 = make_unique<car>(eg_type::hybrid);
v1->Ini();

    return 0;
}
