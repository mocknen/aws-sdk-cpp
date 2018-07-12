﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/dlm/model/LifecyclePolicySummary.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace DLM
{
namespace Model
{

LifecyclePolicySummary::LifecyclePolicySummary() : 
    m_policyIdHasBeenSet(false),
    m_descriptionHasBeenSet(false),
    m_state(GettablePolicyStateValues::NOT_SET),
    m_stateHasBeenSet(false)
{
}

LifecyclePolicySummary::LifecyclePolicySummary(const JsonValue& jsonValue) : 
    m_policyIdHasBeenSet(false),
    m_descriptionHasBeenSet(false),
    m_state(GettablePolicyStateValues::NOT_SET),
    m_stateHasBeenSet(false)
{
  *this = jsonValue;
}

LifecyclePolicySummary& LifecyclePolicySummary::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("PolicyId"))
  {
    m_policyId = jsonValue.GetString("PolicyId");

    m_policyIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Description"))
  {
    m_description = jsonValue.GetString("Description");

    m_descriptionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("State"))
  {
    m_state = GettablePolicyStateValuesMapper::GetGettablePolicyStateValuesForName(jsonValue.GetString("State"));

    m_stateHasBeenSet = true;
  }

  return *this;
}

JsonValue LifecyclePolicySummary::Jsonize() const
{
  JsonValue payload;

  if(m_policyIdHasBeenSet)
  {
   payload.WithString("PolicyId", m_policyId);

  }

  if(m_descriptionHasBeenSet)
  {
   payload.WithString("Description", m_description);

  }

  if(m_stateHasBeenSet)
  {
   payload.WithString("State", GettablePolicyStateValuesMapper::GetNameForGettablePolicyStateValues(m_state));
  }

  return payload;
}

} // namespace Model
} // namespace DLM
} // namespace Aws
