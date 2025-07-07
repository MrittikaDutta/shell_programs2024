#include &lt;stdio.h&gt;
struct Process {
int pid; // Process ID
int arrival; // Arrival time
int burst; // Burst time
int waiting; // Waiting time
int turnaround; // Turnaround time
int completed; // Flag to check if process is completed
};
void calculateTimes(struct Process p[], int n) {
int time = 0, completed = 0;
while (completed != n) {
int idx = -1,i;
int shortestBurst = 1e9;
// Find process with shortest burst time that has arrived
for (i = 0; i &lt; n; i++) {
if (p[i].arrival &lt;= time &amp;&amp; !p[i].completed &amp;&amp; p[i].burst &lt; shortestBurst) {
shortestBurst = p[i].burst;
idx = i;
}
}
if (idx == -1) {
// If no process is available, increase time
time++;
continue;
}
// Process selected
time += p[idx].burst;
p[idx].completed = 1;
completed++;

// Calculate turnaround and waiting times
p[idx].turnaround = time - p[idx].arrival;
p[idx].waiting = p[idx].turnaround - p[idx].burst;
}
}
void printProcessInfo(struct Process p[], int n) {
float avgWaitingTime = 0, avgTurnaroundTime = 0;
int i;
printf(&quot;\nPID\tArrival\tBurst\tWaiting\tTurnaround\n&quot;);
for (i = 0; i &lt; n; i++) {
printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].waiting,
p[i].turnaround);
avgWaitingTime += p[i].waiting;
avgTurnaroundTime += p[i].turnaround;
}
printf(&quot;\nAverage Waiting Time: %.2f&quot;, avgWaitingTime / n);
printf(&quot;\nAverage Turnaround Time: %.2f&quot;, avgTurnaroundTime / n);
}
int main() {
int n,i,j;
printf(&quot;Enter the number of processes: &quot;);
scanf(&quot;%d&quot;, &amp;n);
struct Process p[n];
for (i = 0; i &lt; n; i++) {
p[i].pid = i + 1;
printf(&quot;Enter arrival time and burst time for process %d: &quot;, p[i].pid);
scanf(&quot;%d %d&quot;, &amp;p[i].arrival, &amp;p[i].burst);
p[i].completed = 0;
}
// Sort processes based on arrival time
for (i = 0; i &lt; n - 1; i++) {
for (j = 0; j &lt; n - i - 1; j++) {
if (p[j].arrival &gt; p[j + 1].arrival) {
struct Process temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;
}
}
}
calculateTimes(p, n);
printProcessInfo(p, n);
return 0;

}