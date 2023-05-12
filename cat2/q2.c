/*
Sharma is huilding the student databse to identify the best student based on the student academic records.
He picked few number of students with each stuedent having a specific CGPA til the current semester. 
THe CGPA varies from 7 to 10.
THey are stored in a linear fashion. Identify the best student only based on the available 10 listed students. 
Use the mechanism of referencing and write a program in C language to print the roll no, CGPA of the student and 
reference (address) of the student record.
DO this to print the CGPA Of all the ten students stored.
Sample input: 7.2,8.1,8.3,7.5,9.5,8.4,7.4,9.6,9.2,8.6
Sample Output: Roll No: 1; CGPA: 7.2; REference 65183
*/

struct students{
    int roll;
    float cgpa;
};

int studentfinder(int n, struct students *student){ //passing an array of structures (* here refers to the array passed)
    int i, maxroll=-1;
    float maxcgpa=-1.0;
    for (i=0; i<n; i++){
        if (maxcgpa<(*(student+i)).cgpa){
            maxcgpa=(*(student+i)).cgpa;
            maxroll=(*(student+i)).roll;

        }
    }
    return maxroll;
}

int main(){
    int n;
    scanf("%d",&n);
    struct students students[n];
    for (int i=0; i<n; i++){
        printf("Enter the roll number, CGPA of the student %d", i+1);
        scanf("%d %f", &(students[i].roll), &(students[i].cgpa));
    }
    for (int i=0; i<n; i++){
        printf("Roll number : %d; CGPA :%d; Reference: %x\n", student[i].roll, student[i].cgpa, &student[i]);

    }
    //finding the best student
    int beststudent=studentfinder(n, students);
    printf("The best student details are: \n");
    printf("Roll bo %d\n", beststudent);

return 0;
     
}
