<p align="right">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jblackiex/42_Philosophers?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/jblackiex/42_Philosophers?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/jblackiex/42_Philosophers?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jblackiex/42_Philosophers?color=black" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jblackiex/42_Philosophers?color=green" />
</p>

# 42_Philosophers
Famous dying Philosophers project using threads and mutex in C Language:

• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.

• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.

• There are also forks on the table. There are as many forks as philosophers.

• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.

• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.

• Every philosopher needs to eat and should never starve.

• Philosophers don’t speak with each other.

• Philosophers don’t know if another philosopher is about to die.

• No need to say that philosophers should avoid dying!

• Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

Compile with:
```shell
make
```
<hr>

## 🗿 Execute with:

```shell
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat (optional argument)

-----> (time in milliseconds) <----
```
## 📜 Instructions
◦ number_of_philosophers: The number of philosophers and also the number
of forks.

◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.

◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
