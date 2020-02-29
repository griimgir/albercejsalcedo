
public class Student {

	private String name;
	private char gender;
	private Date birthdate;
	private Preference pref;
	private boolean matched;
	private int score;

	public Student(String name, char gender, Date birthdate, Preference pref){
		this.name = name;
		this.gender = gender;
		this.birthdate = birthdate;
		this.pref = pref;
	}

	//mutators
	public void setName(String name){
		this.name = name;
	}
	public void setGender(char gender){
		this.gender = gender;
	}
	public void setDate(Date birthdate){
		this.birthdate = birthdate;
	}
	public void setPref(Preference pref){
		this.pref = pref;
	}
	public void setMatch(boolean matched){
		this.matched = matched;
	}

	//accessors
	public String getName(){
		return name;
	}
	public char getGender(){
		return gender;
	}
	public Date getDate(){
		return birthdate;
	}
	public Preference getPreference(){
		return pref;
	}
	public boolean getMatched(){
		return matched;
	}

	//compare
	public int compare(Student st){
		if (gender != st.gender)
			return 0;
		score = (40 - pref.compare(st.pref)) + (60 - birthdate.compare(st.birthdate));
		if (score < 0) {
			return 0;
		}
		else if( score > 100) {
			return 100;
		}
		return score;
	}

}
