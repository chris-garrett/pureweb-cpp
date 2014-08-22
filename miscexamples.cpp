#include "miscexamples.h"

using namespace CSI;

static Log::Logger logger = Log::GetLogger<MiscExamples>();

MiscExamples::MiscExamples()
{
	logger.Info.Format("Begin");
}
MiscExamples::~MiscExamples()
{
	logger.Info.Format("End");
}

void MiscExamples::Run()
{
	PrintSizes();
}

void MiscExamples::PrintSizes()
{
	logger.Info.Format("sizeof(CSI::Array<char>):                      {0}", sizeof(CSI::Array<char>));
	logger.Info.Format("sizeof(CSI::ArrayData<char>):                  {0}", sizeof(CSI::ArrayData<char>));
	logger.Info.Format("sizeof(CSI::CountedPtr<CSI::ArrayData<char>>): {0}", sizeof(CSI::CountedPtr<CSI::ArrayData<char>>));
}