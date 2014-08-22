#pragma once

#include "iexample.h"

class StateManagerExamples : public IExample
{
public:
    StateManagerExamples();
	virtual ~StateManagerExamples();

	void Run();
    void UpdateStringValue();

private:
    CSI::CountedPtr<CSI::PureWeb::Server::StateManager> m_stateManager;

    char* GetEventArgString(CSI::Nullable<CSI::String> const& newValue);
	void ConvertOr(CSI::Nullable<CSI::String> const& newValue);
    void OnValueChanged(CSI::ValueChangedEventArgs const& args);
};

