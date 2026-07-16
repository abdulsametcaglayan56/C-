#include <iostream>
using namespace std;

int main() { 
    double number;
    int heal = 5; // Starting with 5 lives (heals)

    do { 
        cout << "\n[Remaining Lives: " << heal << "]" << endl;
        cout << "Enter your guess: ";
        cin >> number;

        // SCENARIO 1: Correct Guess
        if (number == 30) {
            cout << "\n🎉 Congratulations! You found the correct number!" << endl;
            break; // Immediately exit the loop upon winning
        } 
        // SCENARIO 2: Incorrect Guess or Invalid Input
        else {    
            if (number < 30) { 
                cout << "❌ Incorrect. The secret number is HIGHER than your guess." << endl;
                heal--; 
            }
            else if (number > 30) {
                cout << "❌ Incorrect. The secret number is LOWER than your guess." << endl; 
                heal--; 
            }
            // SCENARIO 3: Input Validation (Handling characters, decimals, etc.)
            else { 
                cout << "⚠️ Invalid input! Please enter a valid integer." << endl; 
                cout << "🛡️ Your life has been preserved. Remaining lives: " << heal << endl;
                
                // Clear the error state and flush the input buffer to prevent infinite loops
                cin.clear(); 
                cin.ignore(100, '\n');  
            }
        }    
    } while (number != 30 && heal > 0); // Continue until the number is found or lives reach 0

    // SCENARIO 4: Game Over Check
    if (heal == 0) { 
        cout << "\n💀 Game Over! You have run out of lives. The secret number was 30." << endl; 
    }

    return 0; 
}
