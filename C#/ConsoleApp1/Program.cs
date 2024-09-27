using System;

namespace HelloWorld{
    struct Person{
        public string name;
        public int number;
    }
    class Test{
        static void Main(){
            Person student;
            student.name = "AndyWu";
            student.number = 20270228;
            string a=student.name + student.number.ToString();
            Console.WriteLine($"{a}: \"Hello, "+a+"\"");
            int[] arr = new int[100];
            for(int i=0;i<100;i++){
                arr[i]=i+1;
                Console.WriteLine(arr[i].ToString());
            }
        }
    }
}

/*
凸(＾∇＾)凸
*/