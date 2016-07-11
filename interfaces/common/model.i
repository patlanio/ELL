////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     model.i (interfaces)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

%{
#define SWIG_FILE_WITH_INIT
#include "Node.h"
#include "ModelGraph.h"
#include "Port.h"
#include "InputPort.h"
#include "OutputPort.h"
#include "OutputPortElementList.h"
%}

%rename (ModelGraph) model::Model;

%nodefaultctor model::Node;
%nodefaultctor model::Port;
%nodefaultctor model::OutputPortBase;
%nodefaultctor model::InputPortBase;

%include "Port.h"
%include "OutputPort.h"
%include "OutputPortElementList.h"
%include "Node.h"
%include "ModelGraph.h"
%include "InputPort.h"

%template () model::OutputPort<double>;
%template () model::OutputPort<bool>;
%template () model::OutputPortElementList<double>;
%template () model::OutputPortElementList<bool>;

#ifndef SWIGXML
%template (NodeVector) std::vector<model::Node*>;
%template (PortVector) std::vector<model::Port*>;
%template (InputPortVector) std::vector<model::InputPortBase*>;
%template (OutputPortVector) std::vector<model::OutputPortBase*>;
#endif
