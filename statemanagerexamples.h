#ifndef STATEMANAGEREXAMPLES_H
#define STATEMANAGEREXAMPLES_H

#include "pureweb.h"

class StateManagerExamples
{
public:
    StateManagerExamples();

    void UpdateStringValue();

private:
    CSI::CountedPtr<CSI::PureWeb::Server::StateManager> m_stateManager;

    char* GetEventArgString(CSI::Nullable<CSI::String> const& newValue);
    void OnValueChanged(CSI::ValueChangedEventArgs const& args);
};

#endif // STATEMANAGEREXAMPLES_H
