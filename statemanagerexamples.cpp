#include "statemanagerexamples.h"

using namespace CSI::PureWeb::Server;
using namespace CSI;
using namespace CSI::Threading;
using namespace CSI::PureWeb;
using namespace CSI::PureWeb::Server;

static Log::Logger logger = Log::GetLogger<StateManagerExamples>();

StateManagerExamples::StateManagerExamples()
{
    m_stateManager = new CSI::PureWeb::Server::StateManager("StateManager");
    m_stateManager->XmlStateManager().AddValueChangedHandler("/StringValue", Bind(this, &StateManagerExamples::OnValueChanged));
}

void StateManagerExamples::UpdateStringValue()
{
    CSI::TypelessStateLock lock = m_stateManager->XmlStateManager().AcquireLock();
    lock.SetValue("/StringValue", CSI::Guid().NewGuid().ToString());
}

void StateManagerExamples::OnValueChanged(CSI::ValueChangedEventArgs const& args)
{
	CSI::Nullable<CSI::String> nullable = CSI::String("Testing");
	CSI::String s = nullable.ConvertOr<CSI::String>("");

    logger.Info.Format("OnValueChanged {0}", args.NewValue().ConvertOr<CSI::String>("Empty"));

	ConvertOr(args.NewValue());

    char* out = GetEventArgString(args.NewValue());
    delete out;
}

char* StateManagerExamples::GetEventArgString(CSI::Nullable<CSI::String> const& newValue)
{
    char* str = 0;

    if (newValue.HasValue())
    {
		CSI::String const& value = newValue.ValueByRef();
        CSI::SizeType size = value.Length();
        str = new char[size+1];

        for (unsigned int i=0; i<size; i++)
            str[i]=value[i];

        str[size]=0;

        const char* src = value.ToAscii().begin();

        for (unsigned int i2=0; i2<size; i2++)
            str[i2]=value[i2];
    }

    return str;
}

void StateManagerExamples::ConvertOr(CSI::Nullable<CSI::String> const& newValue)
{
	logger.Info.Format("sizeof(CSI::Array<char>):                      {0}", sizeof(CSI::Array<char>)); 
	logger.Info.Format("sizeof(CSI::ArrayData<char>):                  {0}", sizeof(CSI::ArrayData<char>)); 
	logger.Info.Format("sizeof(CSI::CountedPtr<CSI::ArrayData<char>>): {0}", sizeof(CSI::CountedPtr<CSI::ArrayData<char>>)); 

	CSI::String val = newValue.ConvertOr<CSI::String>("Empty");

	logger.Info.Format("csi str: {0}", val);
	printf("char* foo: %s\n", val.ToAscii().begin());

	// Once ToAscii() goes out of scope (the following line) the pointer goes out of scope. :(
	char* str2 = val.ToAscii().begin();
	printf("char* foo: %s\n", str2);

	// AsciiArray holds underlying ptr to we can work with it. 
	AsciiArray ascii = val.ToAscii();
	char* str = ascii.begin();
	printf("char* foo: %s\n", str);
}
