# PID control algorithm using C++

### How to run the project
1. Clone the repo
2. Run the install.sh file using command line, to install necessary dependencies.
3. This will create a 'build' folder and also create an executable file named `pid`.
4. Place the car simulator file provided by Udacity within the 'build' folder.
5. Run the pid file using command line: `./pid`
6. The program will start listening for data.
7. At the same time, open the simulator and start autonomous mode with Track-1.
8. You should see the car move.

### PID effect
*Here I describe how I arrived at the PID parameters and how they effect the driving behaviour*

Initially, I tried to implement Twiddle to tune the parameters Kp, Kd and Ki (proportional, differential and integram constants respectively). However, it was really hard to tune them because it was very hard to tune each parameter properly, with just one measurement coming in at a time. So I switched to manual tuning, starting from the values used in the lectures by Sebastian.

The proportional constant Kp has the greatest say in how much the car will turn based on CTE. Increasing Kp made the convergence faster, but it also increased oscillations. I realized that having a lower Kp makes for smoother and more comfortable driving, and slowly I reached a value of 0.15.

The differential constant Kd has a large influence on the 'comfort', as it helps reduce oscillations - so I spent the most time just playing with Kd and Kp. Having a high Kd seemed to make the drive smoother, so 12 seems to be a good enough value to pair with a Kp of 0.15.

The integral constant Ki was not much of a priority, because it has a low influence in matters where there's not a lot of bias in the car (as in this case).

One thing I must mention here is that I decided to decelerate the car whenever it was turning too much (i.e. the absolute value of *angle* was greater than 15). It made a world of difference to the car's stability, and avoids most of the rough turns - just like real human drivers!

## License
[GNU General Public License](http://choosealicense.com/licenses/gpl-3.0/#)
