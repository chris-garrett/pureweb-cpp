#include "typelessexamples.h"

using namespace CSI;

static Log::Logger logger = Log::GetLogger<TypelessExamples>();

TypelessExamples::TypelessExamples()
{
	logger.Info.Format("Begin");
}

TypelessExamples::~TypelessExamples()
{
	logger.Info.Format("End");
}

void TypelessExamples::Run()
{
}