public class Preference
{
	private int quietTime;
	private int music;
	private int reading;
	private int chatting;

	// Constructor
	public Preference(int quietTime, int music, int reading, int chatting)
	{
		if(quietTime >= 0 && quietTime <= 10)
		{
			this.quietTime = quietTime;
		}
		else if(quietTime > 10)
		{
			this.quietTime = 10;
		}
		else
		{
			this.quietTime = 0;
		}
		if(music >= 0 && quietTime <= 10)
		{
			this.music = music;
		}
		else if(music > 10)
		{
			this.music = 10;
		}
		else
		{
			this.music = 0;
		}
		if(reading >= 0 && reading <= 10)
		{
			this.reading = reading;
		}
		else if(reading > 10)
		{
			this.reading = 10;
		}
		else
		{
			this.reading = 0;
		}
		if(chatting >= 0 && chatting <= 10)
		{
			this.chatting = chatting;
		}
		else if(chatting > 10)
		{
			this.chatting = 10;
		}
		else
		{
			this.chatting = 0;
		}
	}

	//Getters
	public int getQuietTime()
	{
		return this.quietTime;
	}

	public int getMusic()
	{
		return this.music;
	}

	public int getReading()
	{
		return this.reading;
	}

	public int getChatting()
	{
		return this.chatting;
	}

	//Setters
	public void setQuietTime(int quietTime)
	{
		this.quietTime = quietTime;
	}

	public void setMusic(int music)
	{
		this.music = music;
	}

	public void setReading(int reading)
	{
		this.reading = reading;
	}

	public void setChatting(int chatting)
	{
		this.chatting = chatting;
	}

	// The greater the sum, the less relatable they are
	// The smaller the sum, the more relatable they are.

	public int compare(Preference pref)
	{
		int sum = 0;
		sum += Math.abs(this.quietTime - pref.getQuietTime());
		sum += Math.abs(this.music- pref.getMusic());
		sum += Math.abs(this.reading - pref.getReading());
		sum += Math.abs(this.chatting - pref.getChatting());
		return sum;
	} 

}
