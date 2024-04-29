#include <bits/stdc++.h>
using namespace std;

struct knowledge {};
struct question {
    question* transform(knowledge past) { return new question; }
};
struct answer {};

struct awe {
    inline static int count=0;
    void share() { cout << ++count << " I am in awe!" << endl; }
};
struct person {
    knowledge past;
    
    question* wonder() { return new question; };
    answer* try_solve(question* quest) { return sleep(1), rand()%2 ? nullptr : new answer; }
    knowledge think() { return past; }
    person explore() { return *this; }
    awe unpack_awe() { return awe(); }
};

int main() {
    person you;
    while(true) {
        question* quest = you.wonder();
        answer* solution = you.try_solve(quest);
        while(!solution){
            question* side_quest = quest->transform(you.think())->transform(you.think());
            solution = you.try_solve(side_quest);

            if(!solution) {
                you.explore().unpack_awe().share();
            }
        }
        delete solution;
    }

    return 0;
}