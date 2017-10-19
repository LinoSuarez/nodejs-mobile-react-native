// Copyright 2016 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEPS_CHAKRASHIM_SRC_INSPECTOR_V8_SCHEMA_AGENT_IMPL_H_
#define DEPS_CHAKRASHIM_SRC_INSPECTOR_V8_SCHEMA_AGENT_IMPL_H_

#include "src/base/macros.h"
#include "src/inspector/protocol/Forward.h"
#include "src/inspector/protocol/Schema.h"

namespace v8_inspector {

class V8InspectorSessionImpl;

using protocol::ErrorString;

class V8SchemaAgentImpl : public protocol::Schema::Backend {
 public:
  V8SchemaAgentImpl(V8InspectorSessionImpl*, protocol::FrontendChannel*,
                    protocol::DictionaryValue* state);
  ~V8SchemaAgentImpl() override;

  void getDomains(
      ErrorString*,
      std::unique_ptr<protocol::Array<protocol::Schema::Domain>>*) override;

 private:
  V8InspectorSessionImpl* m_session;
  protocol::Schema::Frontend m_frontend;

  DISALLOW_COPY_AND_ASSIGN(V8SchemaAgentImpl);
};

}  // namespace v8_inspector

#endif  // DEPS_CHAKRASHIM_SRC_INSPECTOR_V8_SCHEMA_AGENT_IMPL_H_