#include <iostream>
#include <vector>
#include <typeinfo>
#include <type_traits>
#include <iterator>

using namespace std;


namespace itertools{

	typedef struct {
		template<typename T>
		T operator ()(T a,T b)const{
			return a+b;
		}
	}plus;

	template <typename Container,typename Function = plus>
	class accumulate{
		
		private:
		    const Container& container;
			const Function& func;

		public:
			accumulate(const Container& cont, const Function& func = plus()):container(cont),func(func){}

		class iterator {

			private:
				typename decay<decltype(*(container.begin()))>::type sum;

				decltype(container.begin()) pos;
				decltype(container.end()) end;
				Function func;

			public:

				iterator(decltype(container.begin()) p,decltype(container.end()) end,Function func): 
					pos(p),end(end),func(func) {
						if(p!=end){
							sum=*p;
						}
					}


				auto operator*() const{
					return sum;
				}

				iterator& operator++() {
					++pos;
					if(pos!=end){
						sum=func(sum,*(pos));
					}
					return *this;
				}

				iterator operator++(int) {
					iterator tmp= *this;
					pos++;
					sum=func(sum,*(pos));
					return tmp;
				}

				bool operator==(const iterator& rhs)  const{
					return pos == rhs.pos;
				}

				bool operator!=(const iterator& rhs) const {
					return pos != rhs.pos;
				}
			};

			iterator begin() const{
				return iterator(container.begin(),container.end(),func);
				
			}

			iterator end() const{
				return iterator(container.end(),container.end(),func);
			}
	};
}
