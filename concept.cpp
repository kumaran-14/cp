/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

class IActor {
    public:
      IActor() {}
      virtual ~IActor() {}
      virtual unique_ptr<IActor> update() = 0;
      virtual void getState() const = 0;
};

class State : public IActor {
    public:
      static const int state = 10;
      virtual ~State() {}
      char state_name;

      State() : state_name('A') {}

      State(char new_name) : state_name(new_name) {}

      virtual void getState() const {
        cout << state_name << endl;
      }

      void printName() {
        cout << state_name << endl;
      }
};

//fwd declaration
class State_B;
class State_A;

class State_A:public State {
    public:
      static const int state_a = 20;
      State_A() : State('A') {}
      unique_ptr<IActor> update() override
      {
        // return make_unique<State_A>();
        // return move(temp);
        // return nullptr;
        return nullptr;
    }
};

class State_B: public State {
    public:
    static const int state_b = 30;
    State_B(): State('B') {}
    unique_ptr<IActor> update() override{
      return make_unique<State_A>();
      // return move(temp);
      return nullptr;
    }
};

class State_C: public State {
    public:
     static const int state_c = 40;

    State_C(): State('C') {}
    unique_ptr<IActor> update() override {
      return make_unique<State_B>();
      // return move(temp);
      return nullptr;
    }
};

template<typename TO, typename FROM>
std::unique_ptr<TO> static_unique_pointer_cast (std::unique_ptr<FROM>&& old){
  return unique_ptr<TO>{static_cast<TO*>(old.release())};  
}


int
main()
{
  // auto derived = make_unique<Derived>();
  // auto base = make_unique<Base>;
  // auto newbase = derived->getNew();

  // cout << newbase->x;
  // auto newx = make_unique<DD>();
  // auto nn = newx->getNN();
  // cout << nn->x;

  unique_ptr<State> curr_state = make_unique<State_B>();
  unique_ptr<IActor> new_state = make_unique<State_C>();
  

  // cout << new_state->state_c << endl;

  curr_state->getState();
  new_state->getState();

  curr_state.reset(static_cast<State*>(new_state.release()));
  // unique_ptr<Derived> foo2 = static_unique_pointer_cast<Derived>(std::move(foo));
  // curr_state = unique_ptr<State>(static_cast<State*>(new_state.release()));
  // std::unique_ptr<SoldierState>(
		    // static_cast<SoldierState *>(new_state.release()));

  // new_state.reset(static_cast<State*>(curr_state->update()));
  auto nnew_state = curr_state->update();

  // new_state->

  // cout<<curr_state->state_name<<endl;
  // cout<<new_state->state_name<<endl;

  curr_state->getState();
  nnew_state->getState();

  return 0;
}
