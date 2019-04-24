### The effect of the P, I, D component of the PID algorithm

  * P: Reduce the current deviation between the sensor value and the target value.
  * I: Reduce the deviation integral value. Prevent steady deviation when the system has bias.
  * D: Reduce the derivative of the deviation. Prevent overshoot with high responsiveness.

### Output movie

The movies shows that the car drive relatively smoothly without leaving the course.

  * P = 0.1
  * I = 0.004
  * D = 1

### How to choose the final hyperparameters

  1. Start parameters: (P, I, D) = (0.2, 0.004, 3)
  2. I tried twiddle. The evaluation function is the integral of the absolute value of the deviation between the sensor value and the target value during 1000 websocket communications.

|  n | p | i | d | dp | di | dd | loss | sum(dp) |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
|  1 | 0.2 | 0.004 | 3 | 0.1 | 0.001 | 1 | 381.526 | 1.101 |
|  2 | 0.3 | 0.004 | 3 | 0.1 | 0.001 | 1 | 312.001 | 1.101 |
|  3 | 0.3 | 0.005 | 3 | 0.11 | 0.001 | 1 | 301.609 | 1.111 |
|  4 | 0.3 | 0.005 | 4 | 0.11 | 0.0011 | 1 | 329.252 | 1.1111 |
|  5 | 0.3 | 0.005 | 2 | 0.11 | 0.0011 | 1 | 327.699 | 1.1111 |
|  6 | 0.41 | 0.005 | 3 | 0.11 | 0.0011 | 0.9 | 277.711 | 1.0111 |
|  7 | 0.41 | 0.0061 | 3 | 0.121 | 0.0011 | 0.9 | 279.531 | 1.0221 |
|  8 | 0.41 | 0.0039 | 3 | 0.121 | 0.0011 | 0.9 | 272.428 | 1.0221 |
|  9 | 0.41 | 0.0039 | 3.9 | 0.121 | 0.00121 | 0.9 | 274.532 | 1.02221 |
|  10 | 0.41 | 0.0039 | 2.1 | 0.121 | 0.001331 | 0.9 | 328.437 | 1.022331 |
|  11 | 0.531 | 0.0039 | 3 | 0.121 | 0.001331 | 0.81 | 304.571 | 0.932331 |
|  12 | 0.289 | 0.0039 | 3 | 0.121 | 0.001331 | 0.81 | 321.07 | 0.932331 |
|  13 | 0.41 | 0.005231 | 3 | 0.1089 | 0.001331 | 0.81 | 297.688 | 0.920231 |

  3. But twiddle is failed. This is because the evaluation of the parameters that makes the car traveling shorter during 1000 communications due to meandering has become high. I wanted to create an evaluation function that integrates the absolute value of the deviation at the same travel distance, but there was a lack of communication information.
  4. Finally, I decided the parameters manually based on the car behavior on the simulator.
