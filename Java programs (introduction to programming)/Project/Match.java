import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Match {

	public static void main(String[] args){
		Scanner key = new Scanner(System.in);

		int space = 100;
		Student[] arr = new Student[space];

		System.out.print("Please give the file name: ");
		String filename = key.next();

		try {
			Scanner fileInput = new Scanner (new FileReader(filename));
			int i = 0;

			while (fileInput.hasNextLine()){	
				Scanner text = new Scanner(fileInput.nextLine());
				text.useDelimiter("[\t\r]");
				String name = text.next();
				String gender = text.next();
				String date = text.next();

				Scanner readBirthDate = new Scanner (date);
				readBirthDate.useDelimiter("-");
				int month = readBirthDate.nextInt();
				int day = readBirthDate.nextInt();
				int year = readBirthDate.nextInt();

				int quietTime = text.nextInt();
				int music = text.nextInt();
				int reading = text.nextInt();
				int chatting = text.nextInt();

				Date birthdate = new Date (month, day, year);
				Preference pref = new Preference(quietTime, music, reading, chatting);
				Student addStudent = new Student(name, gender.charAt(0), birthdate, pref);
				arr[i++] = addStudent;		
			}	
			int max = i;
			for (i = 0; i<max; i++){
				if (!arr[i].getMatched()){
					int Score = 0; 
					int Match = 0;
					for (int j=i+1; j<max;j++){
						if(!arr[j].getMatched()){
							int k = arr[i].compare(arr[j]);
							if (k > Score){
								Score = k;
								Match = j;
							}
						}
					}

					if (Score != 0){
						arr[i].setMatch(true);
						arr[Match].setMatch(true);
						System.out.println(arr[i].getName() + " matches with " + arr[Match].getName() + " with the score " + Score);
					} else
						if (!arr[i].getMatched())
							System.out.println(arr[i].getName() + " has no matches.");
				}
			}
			key.close();
		}catch (NoSuchElementException e){
			System.out.println(e);
		} catch (FileNotFoundException e){
			System.out.println(e);
		}
	}
}

