#include <iostream>

namespace ff {
    template<typename T>
    class Hola {
        private: 
            T id;
        public:
            Hola(T d);
            T getHola() const;
    };
}

template<typename T>
ff::Hola<T>::Hola(T d) {
    id = d;
}
template<typename T>
T ff::Hola<T>::Hola::getHola() const {
    return id;
} 

int main(){
    
    ff::Hola<float> e(2.33);
    std::cout << "Done !\n";
    std::cout << e.getHola() << '\n';
    return 0;

}
