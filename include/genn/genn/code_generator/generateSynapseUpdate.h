#pragma once

// Forward declarations
class ModelSpecMerged;

namespace CodeGenerator
{
class BackendBase;
class CodeStream;
}

//--------------------------------------------------------------------------
// CodeGenerator
//--------------------------------------------------------------------------
namespace CodeGenerator
{
void generateSynapseUpdate(CodeStream &os, const ModelSpecMerged &model, const BackendBase &backend, bool standaloneModules);
}
