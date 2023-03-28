#include <iostream>
#include <chrono>
#include <thread>
#include <assert.h>

class Elevator {
private:
	std::chrono::time_point<std::chrono::system_clock> start_T{};
	std::int32_t To_floor{};
	std::int32_t Old_floor{};
public:
	std::int32_t current_floor{};

	Elevator() = default;
	~Elevator() = default;

	Elevator(const Elevator& x) : current_floor(x.current_floor), 
	    start_T(x.start_T), To_floor(x.To_floor), Old_floor(x.Old_floor) { }

	Elevator& operator= (const Elevator& x) {
		this->current_floor = x.current_floor;
		this->start_T = x.start_T;
		this->To_floor = x.To_floor;
		this->Old_floor = x.Old_floor;
		return *this;
	}

	Elevator(Elevator&& x) : current_floor(std::move(x.current_floor)), 
		start_T(std::move(x.start_T)), To_floor(std::move(x.To_floor)),
		Old_floor(std::move(x.Old_floor)) { }

	Elevator& operator= (Elevator&& x) {
		if ( this != &x ) {
			current_floor = std::move(x.current_floor);
			start_T = std::move(x.start_T);
			To_floor = std::move(x.To_floor);
			Old_floor = std::move(x.Old_floor);
		}
		return *this;
	}


	void display_floor() {
		
		if ( To_floor != current_floor ) {
			// moving
			auto now_T = std::chrono::system_clock::now();
			std::chrono::duration<double> ela_time = now_T - start_T;
			std::int32_t dur = ela_time.count();

			if ( dur >= std::abs(To_floor - Old_floor) ) {
				current_floor = To_floor;
			}
			else {
				auto now = (To_floor > Old_floor) ? dur : -dur;
				current_floor = Old_floor + now;
			}
		}

		std::cout << "current floor is: " << current_floor << "\n";
		
	}

	void move(std::int32_t from, std::int32_t to) {
		assert( from > 0 and from < 11);
		assert( to > 0 and to < 11 );
		start_T = std::chrono::system_clock::now();
		current_floor = from;
		To_floor = to;
		Old_floor = from;
		display_floor();
	}
};