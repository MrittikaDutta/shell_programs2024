#include <stdio.h>;
struct Process {
int pid; // Process ID
int arrival; // Arrival time
int burst; // Burst time
int remaining; // Remaining burst time
int waiting; // Waiting time
int turnaround; // Turnaround time
};
void calculateTimes(struct Process p[], int n) {
int complete = 0, currentTime = 0, shortest = 0;
int minRemaining = 1e9, finishTime;

int isCompleted = 0,i;
while (complete != n) {
// Find the process with the shortest remaining time at the current time
for (i = 0; i &lt; n; i++) {
if (p[i].arrival &lt;= currentTime &amp;&amp; p[i].remaining &gt; 0 &amp;&amp; p[i].remaining &lt; minRemaining) {
minRemaining = p[i].remaining;
shortest = i;
isCompleted = 1;
}
}
if (isCompleted == 0) {
currentTime++;
continue;
}
// Reduce remaining time of the selected process
p[shortest].remaining--;
minRemaining = p[shortest].remaining;
// If a process gets completely executed
if (p[shortest].remaining == 0) {
complete++;
isCompleted = 0;
finishTime = currentTime + 1;
// Calculate waiting and turnaround times
p[shortest].turnaround = finishTime - p[shortest].arrival;
p[shortest].waiting = p[shortest].turnaround - p[shortest].burst;
if (p[shortest].waiting &lt; 0)
p[shortest].waiting = 0;
}
currentTime++;
minRemaining = 1e9; // Reset for the next iteration
}
}
void printProcessInfo(struct Process p[], int n) {
float totalWaitingTime = 0, totalTurnaroundTime = 0;
int i;
printf(&quot;\nPID\tArrival\tBurst\tWaiting\tTurnaround\n&quot;);
for (i = 0; i &lt; n; i++) {
printf(&quot;%d\t%d\t%d\t%d\t%d\n&quot;, p[i].pid, p[i].arrival, p[i].burst, p[i].waiting, p[i].turnaround);
totalWaitingTime += p[i].waiting;
totalTurnaroundTime += p[i].turnaround;
}
printf(&quot;\nAverage Waiting Time: %.2f&quot;, totalWaitingTime / n);
printf(&quot;\nAverage Turnaround Time: %.2f&quot;, totalTurnaroundTime / n);
}
int main() {
int n,i;
printf(&quot;Enter the number of processes: &quot;);
scanf(&quot;%d&quot;, &amp;n);
struct Process p[n];
// Input arrival time and burst time for each process

for (i = 0; i &lt; n; i++) {
p[i].pid = i + 1;
printf(&quot;Enter arrival time and burst time for process %d: &quot;, p[i].pid);
scanf(&quot;%d %d&quot;, &amp;p[i].arrival, &amp;p[i].burst);
p[i].remaining = p[i].burst; // Initialize remaining time with burst time
}
// Function to calculate waiting and turnaround times
calculateTimes(p, n);
// Function to print the results
printProcessInfo(p, n);
return 0;
}