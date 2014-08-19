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
    logger.Info.Format("OnValueChanged {0}", args.NewValue().ConvertOr<CSI::String>("Empty"));

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
