#include <Elevator>

int main()
{

    auto elevator1 = Elevator{}, elevator2 = Elevator{};
    
    //Test move elevator to specifed floor

    elevator1.move(2, 8);
    elevator2.move(9, 1);
    assert( elevator1.current_floor == 2 );
    assert( elevator2.current_floor == 9 );
    
    //Test move a elevator one floor per second
    // a second
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
    elevator1.display_floor();elevator2.display_floor();
    assert( elevator1.current_floor == 3 );
    assert( elevator2.current_floor == 8 );
    //two seconds
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
    elevator1.display_floor();elevator2.display_floor();
    assert( elevator1.current_floor == 5 );
    assert( elevator2.current_floor == 6 );
    
    //Test elevator go to thier destination
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(10));
    elevator1.display_floor();elevator2.display_floor();
    assert( elevator1.current_floor == 8 );
    assert( elevator2.current_floor == 1 );
    
    //Test move twice
    elevator1.move(9, 7);
    elevator2.move(5, 10);
    assert( elevator1.current_floor == 9 );
    assert( elevator2.current_floor == 5 );
    
    //Test move a elevator one floor per second
    // a second
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
    elevator1.display_floor();elevator2.display_floor();
    assert( elevator1.current_floor == 8 );
    assert( elevator2.current_floor == 6 );
    //two seconds
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
    elevator1.display_floor();elevator2.display_floor();
    assert( elevator1.current_floor == 7 );
    assert( elevator2.current_floor == 8 );
    
    //Test elevator go to thier destination
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(10));
    elevator1.display_floor();elevator2.display_floor();
    assert( elevator1.current_floor == 7 );
    assert( elevator2.current_floor == 10 );
    
    return 0;
}