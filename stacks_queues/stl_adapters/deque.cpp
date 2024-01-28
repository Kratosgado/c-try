// // this program demonstrates the STL deque container
// #include <iostream>
// #include <deque>

// int main() {
//    const int MAX = 8;
//    int count;
//    // Max value
//    // Loop counter
//    // Create a deque object.
//    std::deque<int> iDeque;
//    // Enqueue a series of numbers.
//    std::cout << "I will now enqueue items...\n";
//    for (count = 2; count < MAX; count += 2) {
//       std::cout << "Pushing " << count << std::endl;
//       iDeque.push_back(count);
//    }
//    // Dequeue and display the numbers.
//    std::cout << "I will now dequeue items...\n";
//    for (count = 2; count < MAX; count += 2) {
//       std::cout << "Popping " << iDeque.front() << std::endl;
//       iDeque.pop_front();
//    }
//    return 0;
// }