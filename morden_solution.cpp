#include <iostream>
#include <vector>
#include <memory>

class dog
{
public:
    explicit dog(int id_):id(id_){}
    dog(int id_,int b):id(id_){}
    
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

struct animal_concept
{
    virtual ~animal_concept(){}

    virtual void call(int times) const = 0;
};

template<typename T>
struct animal_model : public  animal_concept
{
    template<typename... Args>
    animal_model(Args&&... val):object(std::forward<Args>(val)...){}

    void call(int times) const override
    {
        calling(object,times);
    }

    T object;
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

    using animals = std::vector<std::unique_ptr<animal_concept>>;
    animals as;
    as.emplace_back(std::make_unique<animal_model<dog>>(dog(1)));
    as.emplace_back(std::make_unique<animal_model<dog>>(3,2));
    as.emplace_back(std::make_unique<animal_model<cat>>(cat(1)));
    as.emplace_back(std::make_unique<animal_model<Siamese>>(Siamese(2)));
    as.emplace_back(std::make_unique<animal_model<Husky>>(Husky(2)));
    as.emplace_back(std::make_unique<animal_model<Bulldog>>(Bulldog(3)));
    for(const auto& a : as){
        a->call(3);
    }
    return 0;
}