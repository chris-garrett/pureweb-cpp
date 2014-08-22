#include "stringexamples.h"

using namespace CSI::PureWeb::Server;
using namespace CSI;
using namespace CSI::Threading;
using namespace CSI::PureWeb;
using namespace CSI::PureWeb::Server;

static Log::Logger logger = Log::GetLogger<StringExamples>(); 

StringExamples::StringExamples()
{
	logger.Info.Format("Begin");
}

StringExamples::~StringExamples()
{
	logger.Info.Format("Begin");
}

void StringExamples::Run()
{
	ToStdString();
}

void StringExamples::ToStdString()
{
	CSI::String fromStdString;

	{
		std::string stdString;

		{
			CSI::String csiString = CSI::String("This is a CSI::String");
			stdString = csiString.ToAscii().begin();
		}

		logger.Info.Format("CSI::String to std::string: {0}", stdString);
		fromStdString = stdString;
	}

	logger.Info.Format("std::string to CSI::String: {0}", fromStdString);
}
