#ifndef HEADER_HPP
#define HEADER_HPP

typedef struct s_Date
{
    int day;
    int month;
    int year;

    bool operator<(const s_Date &other) const {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }
} t_Date;


#endif