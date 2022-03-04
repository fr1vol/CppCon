#include <iostream>
#include <vector>
#include <memory>

class dog
{
public:
    explicit dog(int id_):id{id_}{
        std::cout<<"construct \n";
    }

    int get_id() const {
        return id;
    }
private:
    int id;
};

class cat
{
public:
    explicit cat(int id_):id(id_){}

    int get_id() const {
        return id;
    }
private:
    int id;
};

///////////////////////////////////////////
class Husky
{
public:
    explicit Husky(int id_):id{id_}{}

    int get_id() const {
        return id;
    }
private:
    int id;
};

class Bulldog
{
public:
    explicit Bulldog(int id_):id(id_){}

    int get_id() const {
        return id;
    }
private:
    int id;
};

class Siamese
{
public:
    explicit Siamese(int id_):id(id_){}

    int get_id() const {
        return id;
    }
private:
    int id;
};



//////////////////////////////////////////////////

class animal
{
private:

struct animal_concept
{
    virtual ~animal_concept(){}

    virtual void call(int times) const = 0;
    virtual std::unique_ptr<animal_concept> clone() const = 0;
};

template<typename T>
struct animal_model : public  animal_concept
{
    template<typename... Args>
    animal_model(Args&&... val):object(std::forward<Args>(val)...){}

    std::unique_ptr<animal_concept> clone() const override
    {
        return std::make_unique<animal_model>(*this);
    }

    void call(int times) const override
    {
        calling(object,times);
    }

    T object;
};

    friend void  call(const animal& a, int times){
        a.pimpl->call(times);
    }


    std::unique_ptr<animal_concept> pimpl;
    
public:
    template<typename T>
    animal(T&& x): pimpl{new animal_model<T>(std::move(x))}{}

    template<typename T>
    animal(const T& x): pimpl{new animal_model<T>(x)}{}


    animal(const animal& other){
        pimpl = std::move(other.pimpl->clone());
    }
    animal& operator=(const animal& other){
        pimpl = std::move(other.pimpl->clone());
        return *this;
    }
    animal(animal&& a) =default;
    animal& operator=(animal&& a) = default;
};


////////////////////////////////////////// 
// 自由函数

void calling(const dog& d,int times){
    std::cout<<"I'm dog "<<d.get_id()<<" :";
        for(int i =0 ; i < times; ++i){
            std::cout<<"woof ";
        }
        std::cout<<std::endl;
}
void calling(const cat& d,int times){
    std::cout<<"I'm cat "<<d.get_id()<<" :";
        for(int i =0 ; i < times; ++i){
            std::cout<<"mewo ";
        }
        std::cout<<std::endl;
}

void calling(const Husky& d,int times){
    std::cout<<"I'm Husky "<<d.get_id()<<" :";
        for(int i =0 ; i < times; ++i){
            std::cout<<"woof ";
        }
        std::cout<<std::endl;
}

void calling(const Siamese& d,int times){
    std::cout<<"I'm Siamese "<<d.get_id()<<" :";
        for(int i =0 ; i < times; ++i){
            std::cout<<"mewo ";
        }
        std::cout<<std::endl;
}
void calling(const Bulldog& d,int times){
    std::cout<<"I'm Bulldog "<<d.get_id()<<" :";
        for(int i =0 ; i < times; ++i){
            std::cout<<"woof ";
        }
        std::cout<<std::endl;
}



int main()
{
    using animals = std::vector<animal>;
    animals as;
    as.emplace_back(dog{1});
    as.emplace_back(cat{1});
    as.emplace_back(Husky{2});
    as.emplace_back(Siamese{3});
    as.emplace_back(Bulldog{6});
    for(const auto& a : as){
        call(a,4);
    }


    return 0;
}