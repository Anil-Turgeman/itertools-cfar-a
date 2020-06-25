#include <iostream>
#include <stdexcept>

using namespace std;

namespace itertools{
	class range {
		public:
			int Start;
			int End;

			range(int s,int e):Start(s),End(e){
				if(s>e){
					throw new std::logic_error("there is no range\n");
				}
			}

	class iterator {

		private:
			int curr;

		public:
			iterator(int num): curr(num){}

			int operator*() const {
				return curr;
			}

			iterator& operator++() {
				(curr)++;
				return *this;
			}

			const iterator operator++(int) {
				iterator tmp= *this;
				curr++;
				return tmp;
			}

			bool operator==(const iterator& rhs) const {
				return curr == rhs.curr;
			}

			bool operator!=(const iterator& rhs) const {
				return curr!= rhs.curr;
			}
		};

		iterator begin() const{
			return iterator{Start};
		}
		
		iterator end() const{
			return iterator{End};
		}
	};
}
