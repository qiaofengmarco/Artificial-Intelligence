# Artificial Neural Network for Face Recognition
- Lab homepage: http://www.cs.cmu.edu/afs/cs.cmu.edu/user/mitchell/ftp/faces.html
- Important Note: 
  - You can use my code as reference, but please don't directly copy them, because its performance may be poor. (I have analysized the result in my slides.)  
- Code:
  - You can run the Python script "recognizer_linux.py" in Linux and see the result.
    > python recognizer_linux.py
  - You can also train it yourself by modifying codes and re-making them.
    > make all
  - Note that the Neural Network is defined and implemented in "Network.hpp".
- Result Description:
  - Note: You may find a tester in each directory, and you run the Python script.
    > python linux_tester.py
  - First, you can select an image:
    - Both "xxx_2.pgm" and "xxx_4.pgm" could be successfully opened, but "xxx.pgm" can't. It is probably because I use Python PIL Library and it may not provide a support for ".pgm" file in P5 format.)
  
    ![image](https://github.com/qiaofengmarco/Artificial-Intelligence/raw/master/Lab1-Artificial%20Neural%20Network/Result%20Description/1.jpg)

  - Then, the result is displayed: (Note that you may need to re-make the whole project. There could be some problems here.)
  
    ![image](https://github.com/qiaofengmarco/Artificial-Intelligence/raw/master/Lab1-Artificial%20Neural%20Network/Result%20Description/2.jpg)

    ![image](https://github.com/qiaofengmarco/Artificial-Intelligence/raw/master/Lab1-Artificial%20Neural%20Network/Result%20Description/3.jpg)
