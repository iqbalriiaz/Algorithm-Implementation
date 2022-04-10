# <center> Hill Climbing </center>

### Hill Climbing is a heuristic search used for mathematical optimization problems in the field of Artificial Intelligence.

So, given a large set of inputs and a good heuristic function, the algorithm tries to find the best possible solution to the problem in the most reasonable time period. This solution may not be the absolute best(global optimal maximum) but it is sufficiently good considering the time allotted.

The definition above implies that hill-climbing solves the problems where we need to maximize or minimize a given real function by selecting values from the given inputs.

### <b> <u> Key Features </u> </b>

<b> Greedy Approach:</b> The algorithm moves in the direction of optimizing the cost i.e. finding Local Maxima/Minima

<b> No Backtracking:</b> It cannot remember the previous state of the system so backtracking to the previous state is not possible

<b> Feedback Mechanism:</b> The feedback from the previous computation helps in deciding the next course of action i.e. whether to move up or down the slope.

### <b> <u>State Space diagram for Hill Climbing </u> </b>

The State-space diagram is a graphical representation of the set of states(input) our search algorithm can reach vs the value of our objective function(function we intend to maximize/minimize). Here:
1. The X-axis denotes the state space (states or configuration our algorithm may reach.)
2. The Y-axis denotes the values of objective function corresponding to a particular state.
The best solution will be that state space where objective function has maximum/minimum value or global maxima/global minima.

<img src="https://github.com/iqbalriiaz/Algorithm-Implementation/blob/main/Hill-Climbing-Algorithm/images/state_space_diagram.png" alt="ICPC Preliminary" style="height: 100%; width:100%;"/>

<center> <b> FIG:</b> State Space diagram for Hill Climbing </center>
</br>
<b>Local maxima/minima:</b> It is a state which is better than its neighbouring state however there exists a state which is better than it (global maximum). This state is better because here the value of the objective function is higher than its neighbours.

<b>Global maxima/minima:</b> It is the best possible state in the state space diagram. This because at this state, objective function has the highest value.

<b> Plateau/flat local maxima:</b> It is a flat region of state space where neighbouring states have the same value.
Ridge:It is a region which is higher than its neighbour’s but itself has a slope. It is a special kind of local maximum.

### <b> <u> Working of Hill Climbing Algorithm </u> </b>

Hill Climbing is the simplest implementation of a Genetic Algorithm.
Here’s a basic skeleton of the solution.

best = generate_random_solution() </br>
best_score = evaluate_solution(best)

```python
while True:
    print('Best score so far', best_score, 'Solution', best)
    new_solution = copy_solution(best)
    mutate_solution(new_solution)
 
    score = evaluate(new_solution)
    if evaluate(new_solution) < best_score:
        best = new_solution
        best_score = score
```

<b>Step1: Start with a random or an empty solution. This will be our “best solution”. </b>

This function needs to return a random solution. In a hill-climbing algorithm, making this a separate function might be too much abstraction, but if we want to change the structure of our code to a population-based genetic algorithm it will be helpful.

</b>Step2: Evaluate. </b>

<b>Step3: Make a copy of the solution and mutate it slightly. </b>

<b>Step4: Now, evaluate the new solution. If it’s better than the best solution, we replace the best solution with this one. Go to step two and repeat steps 2 and 3. </b>

Basically, to reach a solution to a problem, we’ll need to write three functions.

    1. Creating a random solution.
    2. Evaluating a solution and returning a result.
    3. Mutating the solution in a random fashion.

### <b> <u> Types of Hill Climbing </u> </b>
</br>

<b> <u> 1.Simple Hill Climbing </u> </b>

Simple hill climbing is the simplest way to implement a hill-climbing algorithm. It only evaluates the neighbour node state at a time and selects the first one which optimizes current cost and set it as a current state. It only checks it’s one successor state, and if it finds better than the current state, then move else be in the same state. This algorithm has the following features:
    • Less time consuming
    • Less optimal solution
    • The solution is not guaranteed

<b> Algorithm: </b>

    Step 1:Evaluate the initial state, if it is goal state then return success and Stop.

    Step 2:Loop Until a solution is found or there is no new operator left to apply.

    Step 3:Select and apply an operator to the current state.

    Step 4:Check new state:
        i. If it is goal state, then return success and quit.
        ii. else if it is better than the current state then assign new state as a current state.
        iii. else if not better than the current state, then return to step 2.

    Step 5:Exit.

<b> <u> 2. Steepest-Ascent hill climbing </u> </b>

The steepest-Ascent algorithm is a variation of the simple hill-climbing algorithm. This algorithm examines all the neighbouring nodes of the current state and selects one neighbour node which is closest to the goal state. This algorithm consumes more time as it searches for multiple neighbours.

Algorithm:

    Step 1:Evaluate the initial state, if it is goal state then return success and stop, else make the current state as your initial state.
    Step 2:Loop until a solution is found or the current state does not change.
        i. Let S be a state such that any successor of the current state will be better than it.
        ii. For each operator that applies to the current state;
            ▪ Apply the new operator and generate a new state.
            ▪ Evaluate the new state.
            ▪ If it is goal state, then return it and quit, else compare it to the S.
            ▪ If it is better than S, then set new state as S.
            ▪ If the S is better than the current state, then set the current state to S.
      Step 3:Exit.

<b> <u> 3. Stochastic hill climbing </u> </b>

Stochastic hill climbing does not examine for all its neighbours before moving. Rather, this search algorithm selects one neighbour node at random and evaluate it as a current state or examine another state.

### <b> <u> Problems in different regions in Hill climbing </u> </b>

Hill climbing cannot reach the best possible state if it enters any of the following regions :

<b>1.Local maximum:</b> At a local maximum all neighbouring states have values which are worse than the current state. Since hill-climbing uses a greedy approach, it will not move to the worse state and terminate itself. The process will end even though a better solution may exist.
To overcome the local maximum problem:Utilise the backtracking technique. Maintain a list of visited states. If the search reaches an undesirable state, it can backtrack to the previous configuration and explore a new path.

<b>2.Plateau:</b> On the plateau, all neighbours have the same value. Hence, it is not possible to select the best direction.

To overcome plateaus: Make a big jump. Randomly select a state far away from the current state. Chances are that we will land at a non-plateau region

<b>3.Ridge:</b> Any point on a ridge can look like a peak because the movement in all possible directions is downward. Hence, the algorithm stops when it reaches such a state.

To overcome Ridge: You could use two or more rules before testing. It implies moving in several directions at once.

### <b> <u> Applications of Hill Climbing Technique </u> </b>

    1.Hill Climbing is very useful in routing-related problems like Travelling Salesmen Problem, Job Scheduling, Chip Designing, Portfolio Management, 8-Queens problem, Integrated Circuit design, etc.

    2.Hill Climbing is used in inductive learning methods too. This technique is also used in robotics for coordinating multiple robots in a team.

<b> <u> Simulated Annealing </u> </b>

A hill-climbing algorithm which never makes a move towards a lower value guaranteed to be incomplete because it can get stuck on a local maximum. And if algorithm applies a random walk, by moving a successor, then it may complete but not efficient.
Simulated Annealing is an algorithm which yields both efficiency and completeness.
Mechanically, the term annealing is a process of hardening a metal or glass to a high temperature then cooling gradually, so this allows the metal to reach a low-energy crystalline state.
The same process is used in simulated annealing in which the algorithm picks a random move, instead of picking the best move. If the random move improves the state, then it follows the same path. Otherwise, the algorithm follows the path which has a probability of less than 1 or it moves downhill and chooses another path.

### <b> <u> Problem Solving using hill-climbing algorithm </u> </b>

<b> 0-1 Knapsack Problem </b>

```c++

/*
0/1 knapsack problem
------------------------
item   1   2   3   4   5
--------------------------
P=     10  15  18  8   4 (price/value)
W=     2   5   7   11  3 (weight)

n= 3 (maximum item)
w= 14 (maximum weight)
*/

#include<bits/stdc++.h>
using namespace std;
int P[5]={10,15,18,8,4}, W[5]= {2,5,7,11,3}, n = 3, w= 14, check[5];
int utility_function(){
    int cnt = 0, cntW = 0, cntP = 0;
    for(int i = 0; i < 5; i++){
        if (check[i]==1){
            cnt++;
            cntW = cntW + W[i];
            cntP = cntP + P[i];
            //cout << i << ' ' << cnt << ' ' << cntW << ' ' << cntP << endl;
        }
    }
    if(cnt>n || cntW>w) return -1; //invalid solution
    return cntP;
}


int  main(){
//hill climbing algorithm
// srand(time(NULL)); //[to generate unique random numbers]

    int global = 0;
    while(true){
        for(int i = 0; i<5; i++){
            int x = rand(); //[same pile of random numbers]
            check[i]= x % 2;
            //cout << i << ' ' << x << ' ' << check[i] << endl; 
        }

        int local = utility_function();
        for(int j = 1; j<=1000; j++){
            int index = rand()%5;
            if(check[index]==1) check[index]= 0;
            else check[index]=1;
            local = max(local,utility_function());
            if(global<local){
                global = local;
                for(int i = 0; i < 5; i++){
                    if(check[i]==1){
                        cout << i << endl;
                    } 
                }   cout << endl << endl;
            }
        }
    }
    return 0;
}
```
