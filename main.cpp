#include <iostream>
#include <queue>

using namespace std;

bool isInLanguageL(queue<char> & w);

int main()
{
    string tString;
    queue<char> tQueue;
    cout << "Enter word:";
    cin >> tString;

    for (int i = 0; i < tString.length(); i++)
    {
        tQueue.push(tString[i]);
    }

    cout << isInLanguageL(tQueue);

    return 0;
}

// Check if word belongs to language using queues
bool isInLanguageL(queue<char> & w)
{
    // Declare two queues to keep track of 'a's and 'b's
    queue<char> queueA;
    queue<char> queueB;
    // move through queue to push all 'a's into new queue
    while ((w.size() > 0) and (w.front() == 'a'))
    {
        queueA.push('a');
        // Pop this first element in the queue to move through the queue
        w.pop();
    }
    // move through queue to push all 'b's into new queue
    while ((w.size() > 0) and (w.front() == 'b'))
    {
        queueB.push('b');
        // Pop this first element in the queue to move through the queue
        w.pop();
    }
    // Compare two queue sizes, if queueA is equal to queueB then the word belongs to the language
    // Check if W size is 0, if not then there are letters not placed in correct order, making the word invalid
    // both sizes have to match and w.size() needs to be 0 for a word to pass
    if ((queueA.size() == (queueB.size())) && (w.size() == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
