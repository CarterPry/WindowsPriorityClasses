# Windows Process Priority Setter Script
This script adjusts the priority of the MsPaint software on Windows systems using the `CreateProcessW` function with the Win32 API. I used the (Windows Documentation)[https://learn.microsoft.com/en-us/windows/win32/api/_processthreadsapi/] for the built in functions I used. The priority level of a process prettu much determines how much CPU time it gets compared to the other running processes. Changine the priority level can be extremely important foy system performance and could crash your computer. For example if too much CPU usuage was being used on 1 or more processes, depending on your system resources, even your keyboard and mouse wouldn't be able to function normally because all the focus is now on that modified process.


## Why Process Priority is Important
A higher can be beneficial for time tasks like anit-viruses, howver if a malicous process has high priority level, like real-time, can use up all CPU resources and lead unresponsiveness, or crashes. If malicious software takes up all the system's resources, things like your anti virus might not even be able to function or run.


## Potential Risks
- **Crashing the System**: High-priority processes can consume all CPU cycles and anything vital tasks will not be able to run.
- **Exploitation**: Malware could set its priority high to monopolize all resources and focus, and your security measures won't be able to do a thing.
- **Unresponsiveness**: Main functions like moving your mouse around or clicking can be rendered unresponsive.


## Process Priority Levels
Below is the table of the different priority levels that can be assigned to processes or threads from the (Win32 Documentation)[https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getpriorityclass]:

| Priority Class                 | Hexadecimal | Description                                                                                                  |
|--------------------------------|-------------|--------------------------------------------------------------------------------------------------------------|
| IDLE_PRIORITY_CLASS            | 0x00000040  | Only runs when the system is idle.                                                                           |
| BELOW_NORMAL_PRIORITY_CLASS    | 0x00004000  | Above idle but below normal priority.                                                                        |
| NORMAL_PRIORITY_CLASS          | 0x00000020  | Default priority for processes with no special scheduling needs.                                             |
| ABOVE_NORMAL_PRIORITY_CLASS    | 0x00008000  | Above normal but below high priority.                                                                        |
| HIGH_PRIORITY_CLASS            | 0x00000080  | For time-critical tasks that must execute immediately. Preempts normal or idle priority but use with caution. |
| REALTIME_PRIORITY_CLASS        | 0x00000100  | Highest priority. Can cause system unresponsiveness and should be used very sparingly.                       |


## Script Usage
The script contains two functions: `highPriorityPaint` and `lowPriorityPaint`. Pretty self explanatory.


