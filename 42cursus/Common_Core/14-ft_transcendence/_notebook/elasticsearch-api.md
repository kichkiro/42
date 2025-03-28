# Elasticsearch - API

## ILM Policy

- Get all ILM Policy:
``` sh
curl -X GET 'http://localhost:9200/_ilm/policy/?pretty' -u elastic:elasticpwd
```

- Get a ILM Policy:
``` sh
curl -X GET 'http://localhost:9200/_ilm/policy/ft-transcendence-policy?pretty'\
     -u elastic:elasticpwd
```

- Edit/Create ILM Policy:
``` sh
curl -X PUT 'localhost:9200/_ilm/policy/ft-transcendence_policy'\
     -u elastic:elasticpwd\
     -H 'Content-Type: application/json'\
     -d ' 
{
  "ft-transcendence-policy" : {
    "policy" : {
      "_meta": {
        "description": "used for ft-transcendece logs",
        "project": {
            "name": "ft-transcendence"
        }
      },
      "phases" : {
        "hot" : {
          "min_age" : "0ms",
          "actions" : {
            "set_priority" : {
              "priority" : 100
            }
          }
        },
        "delete" : {
          "min_age" : "1m",
          "actions" : {
            "delete" : {
              "delete_searchable_snapshot" : true
            }
          }
        }
      }
    }
  }
}'
```

- Assign ILM Policy to a index:
``` sh
curl -X PUT 'localhost:9200/.ds-logs-generic-default-2024.07.29-000001/_settings'\
     -u elastic:elasticpwd\
     -H 'Content-Type: application/json'\
     -d '
{
  "index.lifecycle.name": "ft-transcendence-policy"
}' 
```

## Index Template

- Get all Index Templates:
``` sh
curl -X GET "localhost:9200/_index_template?pretty" -u elastic:elasticpwd
```

- Get a Index Template:
``` sh
curl -X GET "localhost:9200/_index_template/ft-transcendence-logs?pretty" -u elastic:elasticpwd
```

- Create/edit a Index Template:
``` sh
curl -X PUT "localhost:9200/_index_template/ft-transcendence-logs?pretty"\
     -u elastic:elasticpwd\
     -H 'Content-Type: application/json'\
     -d '
{
  "name" : "ft-transcendence-logs",
  "index_template" : {
    "index_patterns" : [
      "logs-*-*"
    ],
    "template" : {
      "settings" : {
        "index" : {
          "lifecycle" : {
            "name" : "ft-transcendence-policy"
          }
        }
      },
      # "lifecycle" : {
      #   "enabled" : true,
      #   "data_retention" : "2m"
      # }
    },
    "composed_of" : [
      "logs@mappings",
      "logs@settings",
      "ecs@mappings"
    ],
    "priority" : 100000,
    "data_stream" : {
      "hidden" : false,
      "allow_custom_routing" : false
    },
    "allow_auto_create" : true
  }
}'
```

- Delete a Index Template:
``` sh

```

## Index

- Get all indices:
``` sh
curl -X GET 'http://localhost:9200/_cat/indices' -u elastic:elasticpwd
```

- Get a index:
``` sh
curl -X GET 'http://localhost:9200/.ds-logs-generic-default-2024.07.30-000001/_settings?pretty' -u elastic:elasticpwd
```

- Get last 100 logs for a index:
``` sh
curl -X GET 'http://localhost:9200/logstash-2024.09.04/_search?pretty&size=100' -u elastic:elasticpwd
```

- Get last 100 logs for a index and show only message field:
``` sh
curl -X GET 'http://localhost:9200/.ds-logs-generic-default-2024.07.30-000001/_search?pretty&size=100'\
     -u elastic:elasticpwd\
     -H 'Content-Type: application/json'\
     -d '
{
  "_source": ["timestamp", "message"], 
  "query": {
    "match_all": {}
  }
}'
```

## Data Streams

- Get all datastreams:
``` sh
curl -X GET 'http://localhost:9200/_data_stream?pretty' -u elastic:elasticpwd
```

- Get a datastream:
``` sh
curl -X GET 'http://localhost:9200/_data_stream/logs-generic-default?pretty'\
     -u elastic:elasticpwd
```

- Delete a datastream:
``` sh
curl -X DELETE 'http://localhost:9200/_data_stream/logs-generic-default' \
     -u elastic:elasticpwd
```
