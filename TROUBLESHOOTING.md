## Entry 1: GDB Debugger Not Launching Visually
* **The Issue:** VSCodium’s "Run and Debug" button was unresponsive or stuck on a "GDB" search bar prompt. No visual registers were appearing.

* **System:** Linux (Debian) on ChromeOS.

* **The Fix:** Bypassed the GUI and used the GDB Text User Interface (TUI).

Launched via terminal: gdb ./lab1

* **Set entry breakpoint:** break _start

Used layout regs to display real-time register values (EAX, EBX) during execution.

* **Key Takeaway:** Terminal-based tools are often more reliable than GUI extensions in containerized Linux environments.

## Entry 2: C++ Segmentation Fault
* **The Issue:** Program crashed with "Segmentation Fault (core dumped)."

* **The Fix:** Used GDB to track the pointer address. Realized the array index was out of bounds by 1 (Off-by-one error).

* **The Fix:** Adjusted the for loop condition from i <= size to i < size.
