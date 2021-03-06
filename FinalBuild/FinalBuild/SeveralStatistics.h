#ifndef SEVERAL_STATISTICS_H
#define SEVERAL_STATISTICS_H

#include <vector>
#include <string>
#include <sstream>
#include "MCStatistics.h"
#include "Wrapper.h"

/*
This Class is a decoration for the class MCStatistics. Many different MCStatistics can be passed as argument
together in a vector Inners. The SeveralStats will produce statistics for all the the MCStatistics inside
Inners.
*/

class SeveralStats : public StatisticsMC
{
public:
	SeveralStats(std::vector<Wrapper<StatisticsMC>>& Inners_);

	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double>> GetResultsSoFar() const;
	virtual StatisticsMC* clone() const;
	virtual std::ostringstream GetOutputStream() const;

private:
	std::vector<Wrapper<StatisticsMC>> Inners;
	std::vector<std::string> Names;
};

#endif // !SEVERAL_STATISTICS_H
