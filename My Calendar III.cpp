//Using Map
//Can be done with Segment Trees as well
class MyCalendarThree {
public:
    map<int, int> count;  
    int maxBookings; 

public:
    MyCalendarThree() {
        maxBookings = 0;
    }
    
    int book(int startTime, int endTime) {
        count[startTime]++;    
        count[endTime]--; 
        
        int activeBookings = 0; // Active bookings counter
        for (auto& entry : count) {
            activeBookings += entry.second; 
            maxBookings = max(maxBookings, activeBookings); 
        }
        
        return maxBookings; 
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
