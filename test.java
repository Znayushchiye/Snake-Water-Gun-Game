import java.util.Scanner;

class Snake_Water_Gun_Game 
{
    private static char randomNumber(int number)
    {
        char computerChoice = '@';
        switch(number)
        {
            case 0:computerChoice = 'S';
            break;
            case 1:computerChoice = 'W';
            break;
            case 2:computerChoice = 'G';
        }
        return computerChoice;
    }
    public static void main(String args[])
    {
        int human=0,computer=0;
        char option, again;
        Scanner sc = new Scanner(System.in);

        System.out.println("-----------------------------------------------------------");
        System.out.println("Welcome to the Snake Water Gun game.");
        System.out.println("You'll choose an option and the computer will choose one.");
        System.out.println("The winner gets a point");
        System.out.println("Let's begin. Enter 'y' to start and 'n' to terminate.");

        option = Character.toUpperCase(sc.next().trim().charAt(0));
        if(option == 'Y')
        {
            do{
                System.out.println("\nSnaake...Wateeerrr..Gun!");
                System.out.println(("\'S\' for snake, \'W\' for water, \'G\' for gun"));
                System.out.println("Your move : ");

                char hooman = Character.toUpperCase(sc.next().trim().charAt(0));
                char compooter = Character.toUpperCase(randomNumber((int)((Math.random()*10000)%3)));
                if((hooman=='S'&&compooter=='G')||(hooman=='W'&&compooter=='S')||(hooman=='G'&&compooter=='W'))
                {
                    System.out.println("Computer wins !");
                    computer++;
                }
                else if((hooman=='S'&&compooter=='W')||(hooman=='W'&&compooter=='G')||(hooman=='G'&&compooter=='S'))
                {
                    System.out.println("Human wins !");
                    human++;
                }
                System.out.println("Wanna go again?(y/n)");
                again = Character.toUpperCase(sc.next().trim().charAt(0));
            }while(again=='Y');
            System.out.println("Final Score-");
            System.out.println("Human : "+human);
            System.out.println("Computer : "+computer);
            System.out.println( (human>computer?"Congratulations!! Human wins the match.":(human==computer?"Match tied!!":"You lost! Better luck next time.") );
        }
        else
            System.out.println("See ya !!");
        sc.close();
    }
}
