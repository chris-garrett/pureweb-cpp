#include "standardexamples.h"

using namespace CSI;

static Log::Logger logger = Log::GetLogger<StandardExamples>(); 

StandardExamples::StandardExamples()
{
	logger.Info.Format("Begin");
}

StandardExamples::~StandardExamples()
{
	logger.Info.Format("End");
}

void StandardExamples::Run()
{
}

