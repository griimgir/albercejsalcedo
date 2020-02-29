public class Date
{
	private int day;
	private int month;
	private int year;

	public Date()
	{
		this.month = 1;
		this.day = 1;
		this.year = 2019;
	}
	public Date(int month, int day, int year)
	{
		// If @month is between 1 & 12, then it's ok to set it.
		if(month > 0 && month <= 12)
		{
			this.month = month;
		}
		// Sets the proper amount of days depending on month
		if(month > 0 && month <= 7)
		{
			if(month % 2 == 0 && day > 0 && day <= 30)
			{
				if(month == 2 && day > 0 && day <= 28)
				{
					this.day = day;
				}
				this.day = day;
			}
			else if(day > 0 && day <= 31)
			{
				this.day = day;
			}
		}
		else if(month > 7 && month <= 12)
		{
			if(month % 2 == 0)
			{
				if(day > 0 && day <= 31)
				{
					this.day = day;
				}
			}
			else if(day > 0 && day <= 30)
			{
				this.day = day;
			}
		}
		// Sets year between 1900 & 3000
		if(year > 1899 && year <= 3000)
		{
			this.year = year;
		}
	}

	// Getters
	public int getDay() { return this.day; }
	public int getMonth() { return this.month; }
	public int getYear() { return this.year; }

	// Setters
	public void setDay(int day) { this.day = day; }
	public void setMonth(int month) { this.month = month; }
	public void setYear(int year) { this.year = year; }

	public int compare(Date dt)
	{
		// Find the number of days between the years
		int numDays = (getYear() - dt.getYear()) * 365;
		// Absolute value (just in case)
		if(numDays < 0)
		{
			numDays *= -1;
		}
		// Finds the days and months' difference between the two dates
		int daysDifference = dayOfYear() - dt.dayOfYear();
		// Adds it to the total
		numDays += daysDifference;
		// Converts to months (approximately)
		int approximateMonths = numDays / 30;
		if(approximateMonths > 60)
		{
			return 60;
		}
		return approximateMonths;
	}

	public int dayOfYear()
	{
		int totalDays = 0;
		switch (month)
		{
			case 12: totalDays += 30;
			case 11: totalDays += 31;
			case 10: totalDays += 30;
			case 9: totalDays += 31;
			case 8: totalDays += 31;
			case 7: totalDays += 30;
			case 6: totalDays += 31;
			case 5: totalDays += 30;
			case 4: totalDays += 31;
			case 3: totalDays += 28;
			case 2: totalDays += 31;
		}
		totalDays += day;
		return totalDays;
	}
}
